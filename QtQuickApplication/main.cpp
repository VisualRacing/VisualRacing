#include <string>
#include <QString>
#include <QSharedPointer>
#include <windows.h>

#include <cstdlib>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QThread>
#include <QObject>

#include "vrmainwindow.h"
#include "vrmessage.h"
#include "view/vrplotvelocity.h"
#include "view/vrplotpedals.h"
#include "view/vrplotlaptimebar.h"
#include "view/vrplotrpm.h"
#include "view/vrplotpedalhistory.h"

#include "model/vrdata.h"
#include "model/vrsimulationmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/icon.ico"));

    QQmlApplicationEngine engine;
    QScopedPointer<VRMainWindow> mainWindow(new VRMainWindow);
    QSharedPointer<VRData> vrData;

    vrData = QSharedPointer<VRData>(new VRData());

    /*
     * Create Simulation Manager (for connetcion) connect signals and move to another Thread and start it
     */
    QSharedPointer<VRSimulationManager> simulationManager = QSharedPointer<VRSimulationManager>(new VRSimulationManager(vrData));
    QThread* dataInterfaceThread = new QThread;

    simulationManager->moveToThread(dataInterfaceThread);
    QObject::connect(dataInterfaceThread, SIGNAL(started()), simulationManager.data(), SLOT(start()));
    QObject::connect(simulationManager.data(), SIGNAL(statusChanged(VRMessage*)), mainWindow.data(), SLOT(setItsCurrentMessage(VRMessage*)));
    dataInterfaceThread->start();

    QSharedPointer<VRMessage> connectedMessage = QSharedPointer<VRMessage>(new VRMessage(QString("Application is starting..."), QColor(38, 211, 67)));
    mainWindow->setItsCurrentMessage(connectedMessage);

    /*
     * expose Data-Objects to qml
     */
    engine.rootContext()->setContextProperty("vrMainWindow", mainWindow.data());
    engine.rootContext()->setContextProperty("vrData", vrData.data());

    /*
     * QML-Type Registration
     */
    qmlRegisterType<VRPlotVelocity>("VRPlot", 1, 0, "VRPlotVelocity");
    qmlRegisterType<VRPlotPedals>("VRPlot", 1, 0, "VRPlotPedals");
    qmlRegisterType<VRPlotLapTimeBar>("VRPlot", 1, 0, "VRPlotLapTimeBar");
    qmlRegisterType<VRPlotRPM>("VRPlot", 1, 0, "VRPlotRPM");
    qmlRegisterType<VRPlotPedalHistory>("VRPlot", 1, 0, "VRPlotPedalHistory");

    /*
     * load qml-file
     */
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    /*
     * Start main Loop of UI Application
     */
    int appState = app.exec();

    /*
     * tidy up the running threads
     */
    simulationManager->applicationAboutToQuit();
    dataInterfaceThread->quit();
    dataInterfaceThread->wait();
    delete dataInterfaceThread;

    return appState;
}

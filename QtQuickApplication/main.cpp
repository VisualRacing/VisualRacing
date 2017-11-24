#include <string>
#include <QString>
#include <QSharedPointer>
#include <Windows.h>

#include <cstdlib>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QThread>

#include "vrmainwindow.h"
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

    VRSimulationManager *simulationManager = new VRSimulationManager();

    simulationManager->start();

    QSharedPointer<VRDataInterface> dataInterface;
    do {
        dataInterface = simulationManager->getDataInterface();
    } while(dataInterface.isNull());

    QSharedPointer<VRData> vrData = dataInterface->getBuffer();

    /*
     *  create a VRMainWindow-instanz and expose it to QML
     */
    QScopedPointer<VRMainWindow> mainWindow(new VRMainWindow);
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

    return app.exec();
}

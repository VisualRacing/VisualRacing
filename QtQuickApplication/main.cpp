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
    QSharedPointer<VRSimulationManager> simulationManager;
    QSharedPointer<VRData> vrData;

    bool uiDev = false;
    if (!uiDev) {simulationManager = QSharedPointer<VRSimulationManager>(new VRSimulationManager());
        simulationManager->start();

        QSharedPointer<VRDataInterface> dataInterface;
        do {
            dataInterface = simulationManager->getDataInterface();
        } while(dataInterface.isNull());

        vrData = dataInterface->getBuffer();

        QSharedPointer<VRMessage> connectedMessage = QSharedPointer<VRMessage>(new VRMessage(QString("DataInterface connected successfully."), QColor(38, 211, 67)));
        mainWindow->setItsCurrentMessage(connectedMessage);
    } else {
        vrData = QSharedPointer<VRData>(new VRData());

        QSharedPointer<VRMessage> devMessage = QSharedPointer<VRMessage>(new VRMessage(QString("Ui-Development-Mode active."), QColor(239, 105, 9)));
        mainWindow->setItsCurrentMessage(devMessage);
    }

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

    return app.exec();
}

#include <cstdlib>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "vrmainwindow.h"
#include "vrplotvelocity.h"
#include "vrplotpedals.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/icon.ico"));

    QQmlApplicationEngine engine;

    /*
     *  create a VRMainWindow-instanz and expose it to QML
     */
    QScopedPointer<VRMainWindow> mainWindow(new VRMainWindow);
    engine.rootContext()->setContextProperty("vrMainWindow", mainWindow.data());


    qmlRegisterType<VRPlotVelocity>("VRPlot", 1, 0, "VRPlotVelocity");
    qmlRegisterType<VRPlotPedals>("VRPlot", 1, 0, "VRPlotPedals");


    /*
     * load qml-file
     */
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    /*
     * Example for accesing a qml object from c++
     */
    // QList<QObject*> objectList = engine.rootObjects();
    // QObject* rootObject = objectList.at(0);
    // VRPlotVelocity* velocityPlot = rootObject->findChild<VRPlotVelocity *>("velocityPlot");


    return app.exec();
}

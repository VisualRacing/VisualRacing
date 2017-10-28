#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "vrmainwindow.h"

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/icon.ico"));

    QQmlApplicationEngine engine;

    /*
     *  create a VRMainWindow-instanz and expose it to QML
     */
    QScopedPointer<VRMainWindow> mainWindow(new VRMainWindow);
    engine.rootContext()->setContextProperty("vrMainWindow", mainWindow.data());

    /*
     * load qml-file
     */
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

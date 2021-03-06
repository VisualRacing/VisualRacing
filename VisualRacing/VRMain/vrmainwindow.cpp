#include "vrmainwindow.h"

VRMainWindow::VRMainWindow(QObject *parent) : QObject(parent)
{
    initMessages();

    // itsCurrentMessage must be initialized !!!
    itsCurrentMessage = itsMessages->at(2);     // for example choose this Message

    currentTranslator = QSharedPointer<QTranslator>(new QTranslator);
}


QSharedPointer<QVector<QSharedPointer<VRMessage>>> VRMainWindow::getItsMessages() const
{
    return itsMessages;
}

QString VRMainWindow::getItsCurrentMessageLabel() const
{
    return itsCurrentMessage->getItsLabel();
}

QColor VRMainWindow::getItsCurrentMessageColor() const
{
    return itsCurrentMessage->getItsColor();
}

void VRMainWindow::setItsCurrentMessage(const QSharedPointer<VRMessage> &value)
{
    itsCurrentMessage = value;

    // emit a signal to qml -> messageLabel (statusBar_main) can be updated
    emit itsCurrentMessageChanged();
}

int VRMainWindow::getItsCurrentTab() const
{
    return itsCurrentTab;
}

void VRMainWindow::setItsCurrentTab(int value)
{
    itsLastTab = itsCurrentTab;
    itsCurrentTab = value;
}

int VRMainWindow::getItsLastTab() const
{
    return itsLastTab;
}

void VRMainWindow::setItsLastTab(int value)
{
    itsLastTab = value;
}


void VRMainWindow::initMessages()
{
    // fill itsMessages with the provided Messages
    itsMessages->append(QSharedPointer<VRMessage>(new VRMessage(QString(" "), QColor(255, 255, 255))));
    itsMessages->append(QSharedPointer<VRMessage>(new VRMessage(QString(QObject::tr("loading...")), QColor(255, 255, 255))));
    itsMessages->append(QSharedPointer<VRMessage>(new VRMessage(QString(QObject::tr("Datainterface connected successfully.")), QColor(20, 200, 32))));
    itsMessages->append(QSharedPointer<VRMessage>(new VRMessage(QString(QObject::tr("Problem with connecting datainterface!")), QColor(250, 32, 20))));
}

void VRMainWindow::setEngine(QSharedPointer<QQmlApplicationEngine> engine)
{
    this->engine = engine;
}

void VRMainWindow::switchLanguage(VRSettings::Language language)
{
    QString langName = "English";
    if (language == VRSettings::Language::GERMAN)
        langName = "Deutsch";

    qApp->removeTranslator(currentTranslator.data());
    currentTranslator.data()->load(QString(":/" + langName));
    qApp->installTranslator(currentTranslator.data());

    emit languageChanged();

    // instead op using an emptyString to reevaluating all qsTr, an "engine->retranslate"-call would be possible with Qt 5.10 and higher
    // engine->retranslate();
}

QString VRMainWindow::getEmptyString()
{
    return "";
}

#ifndef VRMAINWINDOW_H
#define VRMAINWINDOW_H

#include <iostream>
#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include <QTranslator>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "vrmessage.h"
#include "vrsettings.h"

/*
 * class VRMainWindow
 *
 * attributes:
 * - itsMessages
 * - itsCurrentMessage
 * - itsCurrentTab
 * - itsLastTab
 *
 * functions:
 * - getItsMessages()
 * - setItsCurrentMessages()
 * INVOKABLE:
 * - QString getItsCurrentMessageLabel()
 * - QColor getItsCurrentMessageColor()
 * - int getItsCurrentTab()
 * - void setItsCurrentTab(int value)
 * - int getItsLastTab()
 * - void setItsLastTab(int value)
 *
 * signals:
 * - void itsCurrentMessageChanged()
 */
class VRMainWindow : public QObject
{
    Q_OBJECT

public:
    explicit VRMainWindow(QObject *parent = nullptr);

    QSharedPointer<QVector<QSharedPointer<VRMessage>>> getItsMessages() const;

    Q_INVOKABLE QString getItsCurrentMessageLabel() const;
    Q_INVOKABLE QColor getItsCurrentMessageColor() const;
    void setItsCurrentMessage(const QSharedPointer<VRMessage> &value);

    Q_INVOKABLE int getItsCurrentTab() const;
    Q_INVOKABLE void setItsCurrentTab(int value);

    Q_INVOKABLE int getItsLastTab() const;
    Q_INVOKABLE void setItsLastTab(int value);

    Q_INVOKABLE void switchLanguage(VRSettings::Language language);
    void setEngine(QSharedPointer<QQmlApplicationEngine> engine);

    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)
    Q_INVOKABLE QString getEmptyString();

signals:
    void itsCurrentMessageChanged();
    void languageChanged();

private:
    QSharedPointer<QVector<QSharedPointer<VRMessage>>> itsMessages = QSharedPointer<QVector<QSharedPointer<VRMessage>>>(new QVector<QSharedPointer<VRMessage>>);
    QSharedPointer<VRMessage> itsCurrentMessage;

    int itsCurrentTab = 0;
    int itsLastTab = 0;
    QSharedPointer<QQmlApplicationEngine> engine;
    QSharedPointer<QTranslator> currentTranslator;

    void initMessages();

};

#endif // VRMAINWINDOW_H

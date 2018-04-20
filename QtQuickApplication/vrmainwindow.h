#ifndef VRMAINWINDOW_H
#define VRMAINWINDOW_H

#include <iostream>
#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include "vrmessage.h"

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


    Q_INVOKABLE int getItsCurrentTab() const;
    Q_INVOKABLE void setItsCurrentTab(int value);

    Q_INVOKABLE int getItsLastTab() const;
    Q_INVOKABLE void setItsLastTab(int value);

public slots:
    void setItsCurrentMessage(const QSharedPointer<VRMessage> &value);
    void setItsCurrentMessage(VRMessage* value);

signals:
    void itsCurrentMessageChanged();

private:
    QSharedPointer<QVector<QSharedPointer<VRMessage>>> itsMessages = QSharedPointer<QVector<QSharedPointer<VRMessage>>>(new QVector<QSharedPointer<VRMessage>>);
    QSharedPointer<VRMessage> itsCurrentMessage;

    int itsCurrentTab = 0;
    int itsLastTab = 0;

    void initMessages();

};

#endif // VRMAINWINDOW_H

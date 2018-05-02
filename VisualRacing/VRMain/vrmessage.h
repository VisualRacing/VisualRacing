#ifndef VRMESSAGE_H
#define VRMESSAGE_H

#include <QObject>
#include <QString>
#include <QColor>

/*
 * class VRMessages
 *
 * attributes:
 * - Qstring itsLabel
 * - QColor itsColor
 *
 */
class VRMessage
{

public:
    VRMessage(QString label, QColor color);

    QString getItsLabel() const;
    void setItsLabel(QString value);

    QColor getItsColor() const;
    void setItsColor(QColor value);

signals:

public slots:

private:
    QString itsLabel;
    QColor itsColor;
};

#endif // VRMESSAGE_H

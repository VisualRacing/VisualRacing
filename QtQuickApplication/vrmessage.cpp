#include "vrmessage.h"

VRMessage::VRMessage(QString label, QColor color)
{
    this->itsLabel = label;
    this->itsColor = color;
}

QString VRMessage::getItsLabel() const
{
    return itsLabel;
}

void VRMessage::setItsLabel(QString value)
{
    itsLabel = value;
}

QColor VRMessage::getItsColor() const
{
    return itsColor;
}

void VRMessage::setItsColor(QColor value)
{
    itsColor = value;
}

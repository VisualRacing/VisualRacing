#include "vrsettings.h"
#include <QDebug>

VRSettings::VRSettings()
{
    this->unit = "Metric";
    this->lang = "English";
    this->theme = "Dark";

    this->load();
}

void VRSettings::load()
{
}

void VRSettings::save()
{
}

QString VRSettings::getUnit() const
{
    return unit;
}

void VRSettings::setUnit(const QString &value)
{
    if (QString::compare(unit, value) == 0)
        return;
    unit = value;

    emit unitChanged();
    this->save();
}

QString VRSettings::getLang() const
{
    return lang;
}

void VRSettings::setLang(const QString &value)
{
    if (QString::compare(lang, value) == 0)
        return;
    lang = value;

    emit langChanged();
    this->save();
}

QString VRSettings::getTheme() const
{
    return theme;
}

void VRSettings::setTheme(const QString &value)
{
    if (QString::compare(theme, value) == 0)
        return;
    theme = value;

    emit themeChanged();
    this->save();
}

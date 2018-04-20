#include "vrthemedata.h"

VRThemeData::VRThemeData(QString name)
{
    changeTheme(name);
}

void VRThemeData::changeTheme(QString name) {
    if (name == "Dark") {
        setAppBackgroundColor("#313537");
        setTabBackgroundColor("#3e4244");
        setTabInactiveColor("#555555");
        setAccentColor("#a7def9");
        setTextColor("white");
    } else if (name == "Light") {
        setAppBackgroundColor("#fcfcfc");
        setTabBackgroundColor("#fff");
        setTabInactiveColor("#eee");
        setAccentColor("#0047ba");
        setTextColor("#333");
    } else {
        // Default to dark theme.
        setAppBackgroundColor("#313537");
        setTabBackgroundColor("#3e4244");
        setTabInactiveColor("#555555");
        setAccentColor("#a7def9");
        setTextColor("white");
    }

    emit themeChanged();
}

QString VRThemeData::getAppBackgroundColor() const
{
    return appBackgroundColor;
}

void VRThemeData::setAppBackgroundColor(const QString &value)
{
    appBackgroundColor = value;
    emit appBackgroundColorChanged();
}

QString VRThemeData::getTabBackgroundColor() const
{
    return tabBackgroundColor;
}

void VRThemeData::setTabBackgroundColor(const QString &value)
{
    tabBackgroundColor = value;
    emit tabBackgroundColorChanged();
}

QString VRThemeData::getTabInactiveColor() const
{
    return tabInactiveColor;
}

void VRThemeData::setTabInactiveColor(const QString &value)
{
    tabInactiveColor = value;
    emit tabInactiveColorChanged();
}

QString VRThemeData::getAccentColor() const
{
    return accentColor;
}

void VRThemeData::setAccentColor(const QString &value)
{
    accentColor = value;
    emit accentColorChanged();
}

QString VRThemeData::getTextColor() const
{
    return textColor;
}

void VRThemeData::setTextColor(const QString &value)
{
    textColor = value;
    emit textColorChanged();
}

#include "vrsettings.h"

VRSettings::VRSettings()
{
    this->path = "settings.vr";
    this->unit = Unit::METRIC;
    this->lang = Language::ENGLISH;
    this->theme = Theme::DARK;

    this->load();
}

void VRSettings::load()
{
    QFile settingsFile(path);
    if (settingsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&settingsFile);
        while(!in.atEnd()) {
            QStringList line = in.readLine().split(":");

            if (line.count() != 2)
                continue;

            QString attribute = line.at(0).trimmed();
            QString value = line.at(1).trimmed();

            if (attribute == "unit") {
                if (value == "metric")
                    unit = Unit::METRIC;
                else if(value == "imperial")
                    unit = Unit::IMPERIAL;
            } else if (attribute == "lang") {
                if (value == "en")
                    lang = Language::ENGLISH;
                else if (value == "de")
                    lang = Language::GERMAN;
            } else if (attribute == "theme") {
                if (value == "dark")
                    theme = Theme::DARK;
                else if (value == "light")
                    theme = Theme::LIGHT;
            }
        }

        settingsFile.close();
    }
}

void VRSettings::save()
{
    QFile settingsFile(path);
    if (settingsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&settingsFile);

        out << "unit:";
        if (unit == Unit::METRIC)
            out << "metric" << endl;
        else if (unit == Unit::IMPERIAL)
            out << "imperial" << endl;

        out << "lang:";
        if (lang == Language::ENGLISH)
            out << "en" << endl;
        else if (lang == Language::GERMAN)
            out << "de" << endl;

        out << "theme:";
        if (theme == Theme::DARK)
            out << "dark" << endl;
        else if (theme == Theme::LIGHT)
            out << "light" << endl;

        settingsFile.close();
    }
}


VRSettings::Theme VRSettings::getTheme() const
{
    return theme;
}

void VRSettings::setTheme(const Theme &value)
{
    if (theme == value)
        return;

    theme = value;
    emit themeChanged();
    save();
}

VRSettings::Language VRSettings::getLang() const
{
    return lang;
}

void VRSettings::setLang(const Language &value)
{
    if (lang == value)
        return;

    lang = value;
    emit langChanged();
    save();
}

VRSettings::Unit VRSettings::getUnit() const
{
    return unit;
}

void VRSettings::setUnit(const Unit &value)
{
    if (unit == value)
        return;

    unit = value;
    emit unitChanged();
    save();
}

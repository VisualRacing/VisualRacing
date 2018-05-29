#include "vrsettings.h"

VRSettings::VRSettings()
{
    this->path = "settings.vr";
    this->unit = Unit::METRIC;
    this->lang = Language::ENGLISH;
    this->theme = Theme::DARK;

    this->load();
}

VRSettings::Unit VRSettings::parseUnit(const QString arg)
{
    // Convert string from settings file to corresponding Unit enum value.
    if (arg == "metric")
        return Unit::METRIC;
    else if(arg == "imperial")
        return Unit::IMPERIAL;

    return Unit::METRIC; // Default to metric.
}

VRSettings::Language VRSettings::parseLanguage(const QString arg)
{
    // Convert string from settings file to corresponding Language enum value.
    if (arg == "en")
        return Language::ENGLISH;
    else if(arg == "de")
        return Language::GERMAN;

    return Language::ENGLISH; // Default to english.
}

VRSettings::Theme VRSettings::parseTheme(const QString arg)
{
    // Convert string from settings file to corresponding Theme enum value.
    if (arg == "dark")
        return Theme::DARK;
    else if (arg == "light")
        return Theme::LIGHT;

    return Theme::DARK; // Default to dark.
}

void VRSettings::load()
{
    QFile settingsFile(path);
    if (settingsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&settingsFile);
        while(!in.atEnd()) {
            // Split line in attribute name and value.
            QStringList line = in.readLine().split(":");

            if (line.count() != 2)
                continue;

            QString attribute = line.at(0).trimmed().toLower();
            QString value = line.at(1).trimmed().toLower();

            // Parse attribute value based on attribute name.
            if (attribute == "unit") {
                unit = parseUnit(value);
            } else if (attribute == "lang") {
                lang = parseLanguage(value);
            } else if (attribute == "theme") {
                theme = parseTheme(value);
            }
        }

        settingsFile.close();
    }
}

QString VRSettings::unitAsString()
{
    // Convert Unit enum value to string for settings file.
    QString s = "unit:";
    if (this->unit == Unit::METRIC)
        s += "metric";
    else if (this->unit == Unit::IMPERIAL)
        s += "imperial";
    return s;
}

QString VRSettings::languageAsString()
{
    // Convert Language enum value to string for settings file.
    QString s = "lang:";
    if (this->lang == Language::ENGLISH)
        s += "en";
    else if (this->lang == Language::GERMAN)
        s += "de";
    return s;
}

QString VRSettings::themeAsString()
{
    // Convert Theme enum value to string for settings file.
    QString s = "theme:";
    if (this->theme == Theme::DARK)
        s += "dark";
    else if (this->theme == Theme::LIGHT)
        s += "light";
    return s;
}

void VRSettings::save()
{
    QFile settingsFile(path);
    if (settingsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&settingsFile);

        out << unitAsString() << endl;
        out << languageAsString() << endl;
        out << themeAsString() << endl;

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

#include "vrsettings.h"

VRSettings::VRSettings()
{
    this->path = "settings.vr";
    this->unit = "Metric";
    this->lang = "English";
    this->theme = "Dark";

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
                if (value == "Metric" || value == "Imperial")
                    unit = value;
            } else if (attribute == "lang") {
                if (value == "English" || value == "Deutsch")
                    lang = value;
            } else if (attribute == "theme") {
                if (value == "Dark" || value == "Light")
                    theme = value;
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

        out << "unit:" << unit << endl;
        out << "lang:" << lang << endl;
        out << "theme:" << theme << endl;

        settingsFile.close();
    }
}

QString VRSettings::getUnit() const
{
    return unit;
}

void VRSettings::setUnit(const QString &value)
{
    if (value == unit)
        return;
    unit = value;

    emit unitChanged();
    save();
}

QString VRSettings::getLang() const
{
    return lang;
}

void VRSettings::setLang(const QString &value)
{
    if (value == lang)
        return;
    lang = value;

    emit langChanged();
    save();
}

QString VRSettings::getTheme() const
{
    return theme;
}

void VRSettings::setTheme(const QString &value)
{
    if (value == theme)
        return;
    theme = value;

    emit themeChanged();
    save();
}

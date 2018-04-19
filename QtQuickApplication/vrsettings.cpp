#include "vrsettings.h"


VRSettings::VRSettings()
{
    this->unit = "Metric";
    this->lang = "English";
    this->theme = "Dark";

    this->load();
}

void VRSettings::load()
{
    QFile settingsFile(":/files/settings.vr");
    if (settingsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {

        QTextStream in(&settingsFile);
        while(!in.atEnd()) {
            QStringList line = in.readLine().split(":");

            if (line.count() != 2)
                continue;

            QString attribute = line.at(0).trimmed();
            QString value = line.at(1).trimmed();

            if (QString::compare(attribute, QString("unit")) == 0) {
                if (QString::compare(value, QString("Metric")) == 0 || QString::compare(value, QString("Imperial")) == 0)
                    unit = value;
            } else if (QString::compare(attribute, QString("lang")) == 0) {
                if (QString::compare(value, QString("English")) == 0 || QString::compare(value, QString("Deutsch")) == 0)
                    lang = value;
            } else if (QString::compare(attribute, QString("theme")) == 0) {
                if (QString::compare(value, QString("Dark")) == 0 || QString::compare(value, QString("Light")) == 0)
                    theme = value;
            }
        }

        settingsFile.close();
    }
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
    save();
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
    save();
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
    save();
}

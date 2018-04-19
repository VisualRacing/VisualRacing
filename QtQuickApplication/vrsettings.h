#ifndef VRSETTINGS_H
#define VRSETTINGS_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QObject>
#include <QFile>
#include <fstream>

class VRSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString unit READ getUnit WRITE setUnit NOTIFY unitChanged)
    Q_PROPERTY(QString lang READ getLang WRITE setLang NOTIFY langChanged)
    Q_PROPERTY(QString theme READ getTheme WRITE setTheme NOTIFY themeChanged)

public:
    VRSettings();

    QString getUnit() const;
    void setUnit(const QString &value);

    QString getLang() const;
    void setLang(const QString &value);

    QString getTheme() const;
    void setTheme(const QString &value);

signals:
    void unitChanged();
    void langChanged();
    void themeChanged();

private:
    void save();
    void load();

    QString path;

    QString unit;
    QString lang;
    QString theme;
};

#endif // VRSETTINGS_H

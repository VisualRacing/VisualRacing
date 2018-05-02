#ifndef VRSETTINGS_H
#define VRSETTINGS_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QObject>
#include <QFile>

class VRSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Unit unit READ getUnit WRITE setUnit NOTIFY unitChanged)
    Q_PROPERTY(Language lang READ getLang WRITE setLang NOTIFY langChanged)
    Q_PROPERTY(Theme theme READ getTheme WRITE setTheme NOTIFY themeChanged)

public:
    enum Unit { METRIC , IMPERIAL };
    Q_ENUM(Unit)
    enum Language { ENGLISH, GERMAN };
    Q_ENUM(Language)
    enum Theme { DARK, LIGHT };
    Q_ENUM(Theme)

    VRSettings();

    Unit getUnit() const;
    void setUnit(const Unit &value);

    Language getLang() const;
    void setLang(const Language &value);

    Theme getTheme() const;
    void setTheme(const Theme &value);

    static Unit parseUnit(const QString arg);
    static Language parseLanguage(const QString arg);
    static Theme parseTheme(const QString arg);

    QString unitAsString();
    QString languageAsString();
    QString themeAsString();

signals:
    void unitChanged();
    void langChanged();
    void themeChanged();

private:
    void save();
    void load();

    QString path;

    Unit unit;
    Language lang;
    Theme theme;
};

Q_DECLARE_METATYPE(VRSettings::Unit)
Q_DECLARE_METATYPE(VRSettings::Language)
Q_DECLARE_METATYPE(VRSettings::Theme)

#endif // VRSETTINGS_H

#ifndef VRTHEMEDATA_H
#define VRTHEMEDATA_H

#include <QObject>
#include <QString>
#include "../vrsettings.h"

class VRThemeData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString appBackgroundColor READ getAppBackgroundColor WRITE setAppBackgroundColor NOTIFY appBackgroundColorChanged)
    Q_PROPERTY(QString tabBackgroundColor READ getTabBackgroundColor WRITE setTabBackgroundColor NOTIFY tabBackgroundColorChanged)
    Q_PROPERTY(QString tabInactiveColor READ getTabInactiveColor WRITE setTabInactiveColor NOTIFY tabInactiveColorChanged)
    Q_PROPERTY(QString accentColor READ getAccentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QString textColor READ getTextColor WRITE setTextColor NOTIFY textColorChanged)

public:
    VRThemeData(VRSettings::Theme theme);

    Q_INVOKABLE void changeTheme(VRSettings::Theme theme);

    QString getAppBackgroundColor() const;
    void setAppBackgroundColor(const QString &value);

    QString getTabBackgroundColor() const;
    void setTabBackgroundColor(const QString &value);

    QString getTabInactiveColor() const;
    void setTabInactiveColor(const QString &value);

    QString getAccentColor() const;
    void setAccentColor(const QString &value);

    QString getTextColor() const;
    void setTextColor(const QString &value);

signals:
    void appBackgroundColorChanged();
    void tabBackgroundColorChanged();
    void tabInactiveColorChanged();
    void accentColorChanged();
    void textColorChanged();

    void themeChanged();

private:
    QString appBackgroundColor;
    QString tabBackgroundColor;
    QString tabInactiveColor;
    QString accentColor;
    QString textColor;
};

#endif // VRTHEMEDATA_H

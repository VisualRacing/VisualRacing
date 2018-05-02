#include <QString>
#include <QtTest>
#include "../VRMain/vrsettings.h"

class VRTest : public QObject
{
    Q_OBJECT

public:
    VRTest();

private Q_SLOTS:
    // void initTestCase();
    // void cleanupTestCase();

    void init();
    void cleanup();

    void testSettingsInitialization();

private:
    VRSettings* settings;
};

VRTest::VRTest()
{
}

void VRTest::init()
{
    settings = new VRSettings();
}

void VRTest::cleanup()
{
    delete settings;
}

void VRTest::testSettingsInitialization()
{
    QVERIFY2(settings->getUnit() == VRSettings::Unit::METRIC, "Wrong default unit system after initialization.");
    QVERIFY2(settings->getLang() == VRSettings::Language::ENGLISH, "Wrong default language after initialization.");
    QVERIFY2(settings->getTheme() == VRSettings::Theme::DARK, "Wrong default theme after initialization.");
}

QTEST_APPLESS_MAIN(VRTest)

#include "tst_vrtest.moc"

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

    void testSettingsInitialization_Unit();
    void testSettingsInitialization_Lang();
    void testSettingsInitialization_Theme();

    void testSettingsParsing_Unit();
    void testSettingsParsing_Lang();
    void testSettingsParsing_Theme();

    void testSettingsStringConversion_Unit();
    void testSettingsStringConversion_Lang();
    void testSettingsStringConversion_Theme();

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

// Initialization tests.
void VRTest::testSettingsInitialization_Unit()
{
    QVERIFY2(settings->getUnit() == VRSettings::Unit::METRIC, "Wrong default unit system after initialization.");
}

void VRTest::testSettingsInitialization_Lang()
{
    QVERIFY2(settings->getLang() == VRSettings::Language::ENGLISH, "Wrong default language after initialization.");
}

void VRTest::testSettingsInitialization_Theme()
{
    QVERIFY2(settings->getTheme() == VRSettings::Theme::DARK, "Wrong default theme after initialization.");
}

// Parsing tests.
void VRTest::testSettingsParsing_Unit()
{
    QVERIFY2(VRSettings::parseUnit("metric") == VRSettings::Unit::METRIC, "'metric' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("METRIC") == VRSettings::Unit::METRIC, "'METRIC' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("meTriC") == VRSettings::Unit::METRIC, "'meTriC' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("VisualRacing") == VRSettings::Unit::METRIC, "Parsing 'VisualRacing' did not result in default VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("imperial") == VRSettings::Unit::IMPERIAL, "'imperial' has not been parsed to VRSettings::Unit::IMPERIAL.");
}

void VRTest::testSettingsParsing_Lang()
{
    QVERIFY2(VRSettings::parseLanguage("en") == VRSettings::Language::ENGLISH, "'en' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("EN") == VRSettings::Language::ENGLISH, "'EN' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("En") == VRSettings::Language::ENGLISH, "'En' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("VisualRacing") == VRSettings::Language::ENGLISH, "Parsing 'VisualRacing' did not result in default VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("de") == VRSettings::Language::GERMAN, "'de' has not been parsed to VRSettings::Language::GERMAN.");
}

void VRTest::testSettingsParsing_Theme()
{
    QVERIFY2(VRSettings::parseTheme("dark") == VRSettings::Theme::DARK, "'dark' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("DARK") == VRSettings::Theme::DARK, "'DARK' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("daRk") == VRSettings::Theme::DARK, "'daRk' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("VisualRacing") == VRSettings::Theme::DARK, "Parsing 'VisualRacing' did not result in default VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("light") == VRSettings::Theme::LIGHT, "'light' has not been parsed to VRSettings::Theme::LIGHT.");
}

// String conversion tests.
void VRTest::testSettingsStringConversion_Unit()
{
    settings->setUnit(VRSettings::Unit::IMPERIAL);
    QVERIFY2(settings->unitAsString() == "unit:imperial", "unitAsString for imperial unit system returned a wrong result.");
    settings->setUnit(VRSettings::Unit::METRIC);
    QVERIFY2(settings->unitAsString() == "unit:metric", "unitAsString for metric unit system returned a wrong result.");
}

void VRTest::testSettingsStringConversion_Lang()
{
    settings->setLang(VRSettings::Language::GERMAN);
    QVERIFY2(settings->languageAsString() == "lang:de", "languageAsString for german language returned a wrong result.");
    settings->setLang(VRSettings::Language::ENGLISH);
    QVERIFY2(settings->languageAsString() == "lang:en", "languageAsString for english language returned a wrong result.");
}

void VRTest::testSettingsStringConversion_Theme()
{
    settings->setTheme(VRSettings::Theme::LIGHT);
    QVERIFY2(settings->themeAsString() == "theme:light", "themeAsString for light theme returned a wrong result.");
    settings->setTheme(VRSettings::Theme::DARK);
    QVERIFY2(settings->themeAsString() == "theme:dark", "themeAsString for dark theme returned a wrong result.");
}

// Execute tests.
QTEST_APPLESS_MAIN(VRTest)

#include "tst_vrtest.moc"

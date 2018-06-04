import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import VRSettings 1.0

Rectangle{
    color: theme.tabBackgroundColor

    Rectangle {
        id: leftRect
        color: "transparent"
        width: parent.width * 0.5
        height: parent.height

        anchors.top: parent.top
        anchors.left: parent.left

        Grid {
            anchors.centerIn: parent
            columns: 2
            columnSpacing: parent.width * 0.125
            rowSpacing: parent.height * 0.075

            Text {
                id: unitLabel
                text: qsTr("Unit System") + vrMainWindow.emptyString
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                id: comboBoxUnit
                width: 200
                model: [qsTr("Metric") + vrMainWindow.emptyString, qsTr("Imperial") + vrMainWindow.emptyString]

                property bool initialized: false
                property int previousIndex: -1
                Component.onCompleted: {
                    currentIndex = 0;
                    if (settings.unit === VRSettings.IMPERIAL)
                        currentIndex = 1;

                    initialized = true;
                }

                onCurrentIndexChanged: {
                    if (!initialized) return;

                    if (previousIndex !== -1) {
                        currentIndex = previousIndex;
                        previousIndex = -1;
                    }

                    if (currentIndex === 0)
                        settings.unit = VRSettings.METRIC;
                    else if (currentIndex === 1)
                        settings.unit = VRSettings.IMPERIAL;
                }
            }

            Text {
                id: languageLabel
                text: qsTr("Language") + vrMainWindow.emptyString
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                id: comboBoxLang
                width: 200
                model: ["English", "Deutsch"]

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = 0;
                    if (settings.lang === VRSettings.GERMAN)
                        currentIndex = 1;

                    initialized = true;
                }

                onCurrentIndexChanged: {
                    if (!initialized) return;

                    if (comboBoxUnit.currentIndex !== 0)
                        comboBoxUnit.previousIndex = comboBoxUnit.currentIndex;
                    if (comboBoxTheme.currentIndex !== 0)
                        comboBoxTheme.previousIndex = comboBoxTheme.currentIndex;

                    var tmpLang = VRSettings.ENGLISH;
                    if (currentIndex === 1)
                        tmpLang = VRSettings.GERMAN;

                    // We have to do this in this order to make sure
                    // that the translator has been loaded when we call
                    // changeLanguage on our plots.
                    vrMainWindow.switchLanguage(tmpLang);
                    settings.lang = tmpLang;
                }
            }

            Text {
                id: themeLabel
                text: qsTr("Theme") + vrMainWindow.emptyString
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                id: comboBoxTheme
                width: 200
                model: [
                    qsTr("Dark") + vrMainWindow.emptyString,
                    qsTr("Light") + vrMainWindow.emptyString
                ]

                property bool initialized: false
                property int previousIndex: -1
                Component.onCompleted: {
                    currentIndex = 0;
                    if (settings.theme === VRSettings.LIGHT)
                        currentIndex = 1;

                    initialized = true;
                }

                onCurrentIndexChanged: {
                    if (!initialized) return;

                    if (previousIndex !== -1) {
                        currentIndex = previousIndex;
                        previousIndex = -1;
                    }

                    if (currentIndex === 0)
                        settings.theme = VRSettings.DARK;
                    else if (currentIndex === 1)
                        settings.theme = VRSettings.LIGHT;

                    theme.changeTheme(settings.theme);
                }
            }
        }
    }

    Rectangle {
        id: rightRect
        color: "transparent"
        width: parent.width * 0.5
        height: parent.height

        anchors.top: parent.top
        anchors.right: parent.right

        Image {
            id: gearImage
            width: parent.width * 0.5
            height: width
            anchors.centerIn: parent
            source: settings.theme === VRSettings.DARK ? "images/settings_gear.svg" : "images/settings_gear_light.svg"
        }
    }
}


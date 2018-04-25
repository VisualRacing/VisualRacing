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
                width: 200
                model: [qsTr("Metric") + vrMainWindow.emptyString, qsTr("Imperial") + vrMainWindow.emptyString]

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = 0;
                    if (settings.unit === VRSettings.IMPERIAL)
                        currentIndex = 1;

                    initialized = true;
                }

                onCurrentIndexChanged: {
                    if (!initialized) return;

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

                    if (currentIndex === 0)
                        settings.lang = VRSettings.ENGLISH;
                    else if (currentIndex === 1)
                        settings.lang = VRSettings.GERMAN;

                    vrMainWindow.switchLanguage(settings.lang);
                }
            }

            Text {
                id: themeLabel
                text: qsTr("Theme") + vrMainWindow.emptyString
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                width: 200
                model: [
                    qsTr("Dark") + vrMainWindow.emptyString,
                    qsTr("Light") + vrMainWindow.emptyString
                ]

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = 0;
                    if (settings.theme === VRSettings.LIGHT)
                        currentIndex = 1;

                    initialized = true;
                }

                onCurrentIndexChanged: {
                    if (!initialized) return;

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


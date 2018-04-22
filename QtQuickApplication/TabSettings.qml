import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

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
                text: qsTr("Unit System")
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                width: 200
                textRole: "text"
                model:
                    ListModel
                    {
                        id: unitListModel
                        ListElement { text: qsTr("Metric")
                                      key: "metric" }
                        ListElement { text: qsTr("Imperial")
                                      key: "imperial" }
                    }

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = Math.max(find(settings.unit), 0);
                    initialized = true;
                }

                onCurrentTextChanged: {
                    if (!initialized) return;
                    settings.unit = currentText;
                }
            }

            Text {
                id: languageLabel
                text: qsTr("Language")
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                width: 200
                textRole: "text"
                model: ListModel {
                    id: languageListModel
                    ListElement { text: "English"; key: "english" }
                    ListElement { text: "Deutsch"; key: "german" }
                }

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = Math.max(find(settings.lang), 0);
                    initialized = true;
                }

                onCurrentTextChanged: {
                    if (!initialized) return;
                    settings.lang = currentText;

                    vrMainWindow.switchLanguage(languageListModel.get(currentIndex).key);
                }
            }

            Text {
                id: themeLabel
                text: qsTr("Theme")
                color: theme.textColor

                font.pointSize: 20
            }

            ComboBox {
                width: 200
                textRole: "text"
                model:
                    ListModel
                    {
                        id: themeListModel
                        ListElement { text: qsTr("Dark")
                                      key: "dark" }
                        ListElement { text: qsTr("Light")
                                      key: "light" }
                    }

                property bool initialized: false
                Component.onCompleted: {
                    currentIndex = Math.max(find(settings.theme), 0);
                    initialized = true;
                }

                onCurrentTextChanged: {
                    if (!initialized) return;
                    settings.theme = currentText;
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
            source: settings.theme == "Dark" ? "images/settings_gear.svg" : "images/settings_gear_light.svg"
        }
    }
}


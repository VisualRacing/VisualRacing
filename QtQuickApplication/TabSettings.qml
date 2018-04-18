import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle{
    color: "#3e4244"

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
                color: "white"

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

                onCurrentTextChanged: {
                    (unitListModel.get(currentIndex).key === "metric") ? unitSystemIsMetric = true : unitSystemIsMetric = false;
                }

            }

            Text {
                id: languageLabel
                text: qsTr("Language")
                color: "white"

                font.pointSize: 20
            }

            ComboBox {
                width: 200
                textRole: "text"
                model:
                    ListModel
                    {
                        id: languageListModel
                        ListElement { text: qsTr("English")
                                      key: "english" }
                        ListElement { text: qsTr("German")
                                      key: "german" }
                    }

                onCurrentTextChanged: {
                    vrMainWindow.switchLanguage(languageListModel.get(currentIndex).key);
                }
            }

            Text {
                id: themeLabel
                text: qsTr("Theme")
                color: "#aaa"

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

                enabled: false
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
            source: "images/settings_gear.svg"
        }
    }
}


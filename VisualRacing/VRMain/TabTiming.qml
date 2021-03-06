import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import VRPlot 1.0

Rectangle{
    color: theme.tabBackgroundColor

    Connections {
        target: settings
        onLangChanged: {
            lapTimeBar.changeLanguage();
        }
     }

    Rectangle {
        id: currentTile
        color: "transparent"
        border.color: theme.accentColor

        width: parent.width * 0.3
        height: parent.height * 0.3

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10

        Rectangle {
            id: currentLapTime
            color: "transparent"

            anchors.top: parent.top
            anchors.left: parent.left

            width: parent.width
            height: parent.height * 0.7

            Text {
                id: currentTimeLabel
                text: lapTimeToString(vrData.currentLapTime)
                color: theme.textColor

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.8
                height: parent.height * 0.7

                font {
                    pointSize: 500
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: currentLaptimeDesc
                text: qsTr("Current Laptime") + vrMainWindow.emptyString
                color: theme.textColor

                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: parent.width * 0.3
                height: parent.height * 0.2

                minimumPointSize: 10
                font.pointSize: 100
                fontSizeMode: Text.Fit

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignBottom
            }
        }

        Rectangle {
            id: currentSector1
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector1Time
                text: sectorTimeToString(vrData.currentS1)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: currentSector2
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector2Time
                text: sectorTimeToString(vrData.currentS2)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: currentSector3
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector3Time
                text: sectorTimeToString(vrData.currentS3)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    /////////////////////////////////////////////////////

    Rectangle {
        id: bestTile
        color: "transparent"
        border.color: theme.accentColor

        width: parent.width * 0.3
        height: parent.height * 0.3

        anchors.top: currentTile.bottom
        anchors.left: parent.left
        anchors.margins: 10
        anchors.topMargin: parent.height * 0.0375

        Rectangle {
            id: bestTime
            color: "transparent"

            width: parent.width
            height: parent.height * 0.7

            anchors.top: parent.top
            anchors.left: parent.left

            Text {
                id: bestTimeLabel
                text: lapTimeToString(vrData.bestLapTime)
                color: theme.textColor

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.8
                height: parent.height * 0.7

                font {
                    pointSize: 500
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text: qsTr("Best Laptime") + vrMainWindow.emptyString
                color: theme.textColor

                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: parent.width * 0.6
                height: parent.height * 0.2

                font.pointSize: currentLaptimeDesc.fontInfo.pointSize

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignBottom
            }
        }

        Rectangle {
            id: sector1
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector1Time
                text: sectorTimeToString(vrData.bestS1)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: sector2
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector2Time
                text: sectorTimeToString(vrData.bestS2)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: sector3
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector3Time
                text: sectorTimeToString(vrData.bestS3)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

    }

    /////////////////////////////////////////////////////

    Rectangle {
        id: theorBestTile
        color: "transparent"
        border.color: theme.accentColor

        width: parent.width * 0.3
        height: parent.height * 0.3

        anchors.top: bestTile.bottom
        anchors.left: parent.left
        anchors.margins: 10
        anchors.topMargin: parent.height * 0.0375

        Rectangle {
            id: theorBestTime
            color: "transparent"

            width: parent.width
            height: parent.height * 0.7

            anchors.top: parent.top
            anchors.left: parent.left

            Text {
                id: theorBestTimeLabel
                text: lapTimeToString(vrData.tBestS1 + vrData.tBestS2 + vrData.tBestS3)
                color: theme.textColor

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.8
                height: parent.height * 0.7

                font {
                    pointSize: 500
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text: qsTr("Theoretical Best Laptime") + vrMainWindow.emptyString
                color: theme.textColor

                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: parent.width * 0.6
                height: parent.height * 0.2

                font.pointSize: currentLaptimeDesc.fontInfo.pointSize

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignBottom
            }
        }

        Rectangle {
            id: bestSector1
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector1Time
                text: sectorTimeToString(vrData.tBestS1)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: bestSector2
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector2Time
                text: sectorTimeToString(vrData.tBestS1 + vrData.tBestS2)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: bestSector3
            color: "transparent"
            border.color: theme.accentColor

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector3Time
                text: sectorTimeToString(vrData.tBestS1 + vrData.tBestS2 + vrData.tBestS3)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8

                font {
                    pointSize: 500
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

    }

    /////////////////////////////////////////////////////////////

    Rectangle {
        color: "transparent"
        border.color: theme.accentColor
        width: parent.width * 0.67
        height: parent.height * 0.7
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10

        TableView {
             id: lapTimeTable
             anchors.fill: parent
             anchors.margins: 1

             frameVisible: false

             style: TableViewStyle {
                 backgroundColor: theme.tabBackgroundColor
                 alternateBackgroundColor: Qt.lighter(theme.tabBackgroundColor, 1.2)
                 textColor: theme.accentColor

                 headerDelegate: Rectangle {
                    height: headerText.implicitHeight * 0.2
                    width: headerText.implicitWidth
                    color: Qt.darker(theme.tabBackgroundColor, 1.2)

                    anchors.margins: 100

                    Text {
                        id: headerText
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: styleData.textAlignment
                        anchors.leftMargin: 12
                        text: styleData.value
                        color: textColor

                        minimumPixelSize: 10
                        font.pixelSize: 100
                        fontSizeMode: Text.Fit
                    }
                 }

                 itemDelegate: Item {
                     height: itemText.implicitHeight
                     width: itemText.implicitWidth
                     Text {
                         id: itemText
                         anchors.fill: parent
                         verticalAlignment: Text.AlignVCenter
                         horizontalAlignment: styleData.textAlignment
                         anchors.leftMargin: 12
                         text: styleData.value
                         color: textColor

                         minimumPixelSize: 10
                         font.pixelSize: 100
                         fontSizeMode: Text.Fit
                     }
                  }
             }

             TableViewColumn {
                 id: columnNumber
                 title: qsTr("No.") + vrMainWindow.emptyString
                 role: "number"
                 width: lapTimeTable.viewport.width * 0.1

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnLaptime
                 title: qsTr("Laptime") + vrMainWindow.emptyString
                 role: "laptime"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector1
                 title: qsTr("Sector 1") + vrMainWindow.emptyString
                 role: "sector1"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector2
                 title: qsTr("Sector 2") + vrMainWindow.emptyString
                 role: "sector2"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector3
                 title: qsTr("Sector 3") + vrMainWindow.emptyString
                 role: "sector3"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             // How-To add data to model: insert(0, ...) in front and append(...) at the end
             // model.insert(0, {"number": "88", "laptime": "1:49:33s", "sector1":  "88s", "sector2": "12s", "sector3": "29.04s"})
             // model.append({"number": 88, "laptime": "1:49:33s", "sector1":  "88s", "sector2": "12s", "sector3": "29.04s"})

             model: ListModel {
                 id: model
            }
        }
    }

    /////////////////////////////////////////////

    VRPlotLapTimeBar {
        id: lapTimeBar
        objectName: "lapTimeBar"
        width: parent.width * 0.67
        height: parent.height * 0.25
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        Component.onCompleted: initCustomPlot(theme)

        /* Laptime table and chart update */
        Connections {
            target: vrData
            onPreviousLapTimeChanged: lapTimeBar.performUpdate(vrData.previousLapTime, vrData.previousS1, vrData.previousS2, vrData.previousS3)
            onPreviousS1Changed: lapTimeBar.performUpdate(vrData.previousLapTime, vrData.previousS1, vrData.previousS2, vrData.previousS3)
            onPreviousS2Changed: lapTimeBar.performUpdate(vrData.previousLapTime, vrData.previousS1, vrData.previousS2, vrData.previousS3)
            onPreviousS3Changed: lapTimeBar.performUpdate(vrData.previousLapTime, vrData.previousS1, vrData.previousS2, vrData.previousS3)
        }

        Connections {
            target: theme
            onThemeChanged: lapTimeBar.setTheme(theme)
        }

        property int updateCounter: 0
        function performUpdate(laptime, s1, s2, s3) {
            updateCounter++;

            if (updateCounter == 4) {
                update(laptime, s1, s2, s3);
                updateCounter = 0;
            }
        }

        function update(laptime, s1, s2, s3) {
            var timeInS1 = s1;
            var timeInS2 = s2 - s1;
            var timeInS3 = s3 - s2;

            lapTimeBar.pushData(laptime, timeInS1, timeInS2, timeInS3, vrData.bestLapTime); // TODO: Is it guaranteed that the best laptime has been updated by now?
            model.insert(0, {"number": (laptime > 0 ? "lap " + (model.count + 1) : "INVALID" ), "laptime": lapTimeToString(laptime), "sector1": sectorTimeToString(s1), "sector2": sectorTimeToString(s2), "sector3": sectorTimeToString(s3)});

            if (laptime <= 0) // The lap was invalid.
                return;

            if (vrData.tBestS1 <= 0 || timeInS1 < vrData.tBestS1) {
                vrData.tBestS1 = timeInS1;
            }
            if (vrData.tBestS2 <= 0 || timeInS2 < vrData.tBestS2) {
                vrData.tBestS2 = timeInS2;
            }
            if (vrData.tBestS3 <= 0 || timeInS3 < vrData.tBestS3) {
                vrData.tBestS3 = timeInS3;
            }
        }
    }
}

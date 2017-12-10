import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import VRPlot 1.0

Rectangle{
    color: "#3e4244"

    Rectangle {
        id: currentTile
        color: "transparent"
        border.color: "#a7def9"

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
                color: "white"

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
                text: "Current Laptime"
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector1Time
                text: sectorTimeToString(vrData.currentS1)
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector2Time
                text: sectorTimeToString(vrData.currentS2)
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: currentSector3Time
                text: sectorTimeToString(vrData.currentS3)
                color: "white"

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
        border.color: "#a7def9"

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
                color: "white"

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
                text: "Best Laptime"
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector1Time
                text: sectorTimeToString(vrData.bestS1)
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector2Time
                text: sectorTimeToString(vrData.bestS2)
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: sector3Time
                text: sectorTimeToString(vrData.bestS3)
                color: "white"

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
        border.color: "#a7def9"

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
                text: "1:49.672"
                color: "white"

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
                text: "Theoretical best Laptime"
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector1Time
                text: "Best S1"
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector2Time
                text: "Best S2"
                color: "white"

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
            border.color: "#a7def9"

            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width / 3
            height: parent.height * 0.3

            Text {
                id: bestSector3Time
                text: "Best S3"
                color: "white"

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
        border.color: "#a7def9"
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
                 backgroundColor: "#3e4244"
                 alternateBackgroundColor: "#404446"
                 textColor: "white"

                 headerDelegate: Rectangle {
                    height: headerText.implicitHeight * 0.2
                    width: headerText.implicitWidth
                    color: "#343839"

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
                 title: "No."
                 role: "number"
                 width: lapTimeTable.viewport.width * 0.1

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnLaptime
                 title: "Laptime"
                 role: "laptime"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector1
                 title: "Sector 1"
                 role: "sector1"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector2
                 title: "Sector 2"
                 role: "sector2"
                 width: lapTimeTable.viewport.width * (.9 * 0.25)

                 movable: false
                 resizable: false
             }

             TableViewColumn {
                 id: columnSector3
                 title: "Sector 3"
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

                 ListElement {
                     number: "12"
                     laptime: "1:49.33s"
                     sector1: "43.1s"
                     sector2: "39.7s"
                     sector3: "29.04s"
                 }
                 ListElement {
                     number: "11"
                     laptime: "1:49.33s"
                     sector1: "43.1s"
                     sector2: "39.7s"
                     sector3: "29.04s"
                 }
                 ListElement {
                     number: "10"
                     laptime: "1:49.33s"
                     sector1: "43.1s"
                     sector2: "39.7s"
                     sector3: "29.04s"
                 }
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

        Component.onCompleted: initCustomPlot()

        Timer {
            interval: 2000
            running: true
            repeat: true
            onTriggered: lapTimeBar.push()
        }

        // push some Demo data
        function push(){
            var rand = Math.random() * (120 - 80) + 80;
            lapTimeBar.pushData(rand, rand*0.2, rand*0.5, rand*0.3, 75);
        }
    }
}

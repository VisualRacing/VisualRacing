import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import VRPlot 1.0

Rectangle{
    color: "#3e4244"

    TableView {
        id: lapTimeTable
        width: parent.width * 0.67
        height: parent.height * 0.7
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10

        style: TableViewStyle {
            backgroundColor: "#3e4244"
            alternateBackgroundColor: "#404446"
            textColor: "white"
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

        model: ListModel {
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

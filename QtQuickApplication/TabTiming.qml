import QtQuick 2.0
import QtQuick.Controls 1.4
import VRPlot 1.0

Rectangle{
    color: "#3e4244"

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

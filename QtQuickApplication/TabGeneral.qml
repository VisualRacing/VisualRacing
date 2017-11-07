import QtQuick 2.0
import VRPlot 1.0

Rectangle{
    color: "#3e4244"

        VRPlotVelocity {

            property double index: 0

            id: velocityPlot
            objectName: "velocityPlot"
            width: parent.width * 0.5
            height: parent.height * 0.5
            anchors.left: parent.left
            anchors.top: parent.top

            Component.onCompleted: initCustomPlot()

            Timer {
                interval: 50
                running: true
                repeat: true
                onTriggered: velocityPlot.push()
            }

            // push some Demo data
            function push(){
                velocityPlot.pushData(velocityPlot.index, (Math.sin(velocityPlot.index) * 120 + 120))
                velocityPlot.index += 0.1;
            }

        }

        VRPlotPedals {

            id: pedalsPlot
            width: parent.width * 0.5
            height: parent.height * 0.5
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            Component.onCompleted: init()

            // push some Demo data
            function init(){
                initCustomPlot();
                pushData(100, 30, 65);
            }
        }
}

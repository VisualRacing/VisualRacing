import QtQuick 2.0

Rectangle{
    color: theme.appBackgroundColor

    Text {
        id: accelBehav
        text: "AccelBehav: " + vrMetrics.accelBehav
        color: "#FFFFFF"
        anchors.top: parent.top
    }
    Text {
        id: avgAccelBehav
        text: "AvgAccelBehav: " + vrMetrics.avgAccelBehav
        color: "#FFFFFF"
        anchors.top: accelBehav.bottom
    }
    Text {
        id: clutchDisengagedTime
        text: "ClutchDisengagedTime: " + vrMetrics.clutchDisengagedTime
        color: "#FFFFFF"
        anchors.top: avgAccelBehav.bottom
    }
    Text {
        id: avgClutchDisengagedTime
        text: "Avg ClutchDisengagedTime: " + vrMetrics.avgClutchDisTime
        color: "#FFFFFF"
        anchors.top: clutchDisengagedTime.bottom
    }
    Text {
        id: gearChangeTime
        text: "GearChangeTime: " + vrMetrics.gearChangeTime
        color: "#FFFFFF"
        anchors.top: avgClutchDisengagedTime.bottom
    }
    Text {
        id: avgGearChangeTime
        text: "Avg GearChangeTime: " + vrMetrics.avgGearChangTime
        color: "#FFFFFF"
        anchors.top: gearChangeTime.bottom
    }
}

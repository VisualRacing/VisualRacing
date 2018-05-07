import QtQuick 2.0

Rectangle{
    color: theme.appBackgroundColor

    Text {
        id: tFL
        text: "TG_FL: " + vrData.tireGripFL.toFixed(3)
        color: theme.textColor
    }
    Text {
        id: tFR
        anchors.top: tFL.bottom
        text: "TG_FR: " + vrData.tireGripFR.toFixed(3)
        color: theme.textColor
    }
    Text {
        id: tRR
        anchors.top: tFR.bottom
        text: "TG_RR: " + vrData.tireGripRR.toFixed(3)
        color: theme.textColor
    }
    Text {
        id: tRL
        anchors.top: tRR.bottom
        text: "TG_RL: " + vrData.tireGripRL.toFixed(3)
        color: theme.textColor
    }

    Text {
        id: tLD
        anchors.top: tRL.bottom
        text: "LD: " + vrData.lapDistance.toFixed(3)
        color: theme.textColor
    }
    Text {
        id: tLDF
        anchors.top: tLD.bottom
        text: "LDF: " + vrData.lapDistanceFraction.toFixed(3)
        color: theme.textColor
    }
}

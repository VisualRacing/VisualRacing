import QtQuick 2.0

Rectangle{
    color: "#3e4244"

    TireInfoPanel {
        id: tireObject
        width: parent.width * 0.56
        height: parent.height * 0.9
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: parent.height * 0.05
        anchors.rightMargin: parent.width * 0.02
        border.color: "#a7def9"
    }
}


import QtQuick 2.0

Rectangle{
    color: "#3e4244"

    TireInfoPanel {
        id: tireObject
        width: parent.width * 0.56
        height: parent.height * 0.9
        anchors.centerIn: parent
        border.color: "#a7def9"
    }
}

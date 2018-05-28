import QtQuick 2.0

Rectangle{
    color: theme.appBackgroundColor

    Rectangle {
        id: gripContainer
        anchors.left: parent.left
        anchors.top: parent.top
        width: parent.width * 0.15
        height: parent.height * 0.45
        anchors.leftMargin: parent.width * 0.01
        anchors.topMargin: parent.width * 0.01

        color: theme.tabBackgroundColor

        Rectangle {
            id: frontLeft
            anchors.left: parent.left
            anchors.top: parent.top
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.leftMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            color: theme.appBackgroundColor
            border.color: percToColor(vrData.tireGripFL)

            Rectangle {
                width: parent.width
                height: parent.height * (1 - vrData.tireGripFL)
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripFL)
            }
        }

        Rectangle {
            id: frontRight
            anchors.right: parent.right
            anchors.top: parent.top
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.rightMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            color: theme.appBackgroundColor
            border.color: percToColor(vrData.tireGripFR)

            Rectangle {
                width: parent.width
                height: parent.height * (1 - vrData.tireGripFR)
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripFR)
            }
        }

        Rectangle {
            id: rearLeft
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.leftMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            color: theme.appBackgroundColor
            border.color: percToColor(vrData.tireGripRL)

            Rectangle {
                width: parent.width
                height: parent.height * (1 - vrData.tireGripRL)
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripRL)
            }
        }

        Rectangle {
            id: rearRight
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.rightMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            color: theme.appBackgroundColor
            border.color: percToColor(vrData.tireGripRR)

            Rectangle {
                width: parent.width
                height: parent.height * (1 - vrData.tireGripRR)
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripRR)
            }
        }
    }
}

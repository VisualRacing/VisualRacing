import QtQuick 2.0

Rectangle{
    color: theme.appBackgroundColor

    Rectangle {
        id: accelBehav
        anchors.left: parent.left
        anchors.top: parent.top
        height: parent.height
        width: parent.width * .35

        color: theme.appBackgroundColor

        Text {
            id: accelBehavTitle
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            width: parent.width - 30

            color: theme.tabBackgroundColor
            text: qsTr("Acceleration")

            font {
                pointSize: 50
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
        }

        Rectangle {
            id: gripContainer
            anchors.left: parent.left
            anchors.top: parent.top
            width: parent.width * 0.5
            height: parent.height * 0.45
            anchors.margins: 15

            color: theme.appBackgroundColor
            border.color: theme.accentColor

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

    Rectangle {
        id: general
        anchors.centerIn: parent
        height: parent.height
        width: parent.width * .3

        color: theme.appBackgroundColor
        border.color: theme.accentColor

        Rectangle {
            id: pedalInfo

            anchors.top: parent.top
            height: parent.height * 0.5
            width: parent.width

            color: theme.tabBackgroundColor

            Rectangle {
                id: clutch

                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                anchors.verticalCenter: brake.verticalCenter
                height: parent.height * 0.8
                width: parent.width * 0.2

                color: theme.appBackgroundColor

                Rectangle {
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: parent.height * vrData.clutch

                    color: "#394ead"
                }
            }

            Rectangle {
                id: brake

                anchors.centerIn: parent
                height: parent.height * 0.8
                width: parent.width * 0.2

                color: theme.appBackgroundColor

                Rectangle {
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: parent.height * vrData.brake

                    color: "#ad3954"
                }
            }

            Rectangle {
                id: throttle

                anchors.right: parent.right
                anchors.rightMargin: parent.width * 0.1
                anchors.verticalCenter: brake.verticalCenter
                height: parent.height * 0.8
                width: parent.width * 0.2

                color: theme.appBackgroundColor

                Rectangle {
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: parent.height * vrData.throttle

                    color: "#3dad39"
                }
            }
        }

        Rectangle {
            id: drivetrainInfo

            anchors.bottom: parent.bottom
            height: parent.height * 0.5
            width: parent.width

            color: theme.tabBackgroundColor

            Rectangle { // TODO: Copy and pasted from general tab
                id: revCounterContainer
                width: parent.width * 0.9
                height: parent.height * 0.15
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.margins: 15

                color: theme.appBackgroundColor;

                Rectangle {
                    id: revCounter
                    width: parent.width * (vrData.rpm / vrData.maxRpm)
                    height: parent.height
                    anchors.top: parent.top
                    anchors.left: parent.left

                    color: (vrData.rpm / vrData.maxRpm) > 0.9 ? "red" : "lime"
                }
            }

            Text { // TODO: Copy and pasted from general tab
                id: gearLabel
                text: gearIndexToChar(vrData.gear)
                color: theme.textColor

                anchors.centerIn: parent
                width: parent.width * 0.4
                height: parent.height * 0.7

                font {
                    pointSize: 500
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }

    Rectangle {
        id: upShift
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height
        width: parent.width * .35

        color: theme.appBackgroundColor

        Text {
            id: upShiftTitle
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            width: parent.width - 30
            horizontalAlignment: Text.AlignRight

            color: theme.tabBackgroundColor
            text: qsTr("Upshift")

            font {
                pointSize: 50
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
        }
    }
}

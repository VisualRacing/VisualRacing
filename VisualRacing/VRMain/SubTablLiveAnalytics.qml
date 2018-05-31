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
            text: qsTr("Acceleration") + vrMainWindow.emptyString

            font {
                pointSize: 50
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
        }

        Rectangle {
            id: curAccel
            width: parent.width
            height: parent.height * 0.33
            anchors.left: parent.left
            anchors.top: parent.top

            color: "transparent"

            Text {
                color: theme.textColor
                text: qsTr("Current value") + vrMainWindow.emptyString

                height: parent.height * 0.2
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 5

                font {
                    pointSize: 50
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: percToColor(vrMetrics.accelBehav) // theme.textColor
                text: vrMetrics.accelBehav.toFixed(3)

                height: parent.height * 0.8
                width: parent.width
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                font {
                    pointSize: 70
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: avgAccel
            width: parent.width
            height: parent.height * 0.33
            anchors.left: parent.left
            anchors.top: curAccel.bottom

            color: "transparent"

            Text {
                color: theme.textColor
                text: qsTr("Average") + vrMainWindow.emptyString

                height: parent.height * 0.2
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 5

                font {
                    pointSize: 50
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: theme.textColor
                text: vrMetrics.avgAccelBehav.toFixed(3)

                height: parent.height * 0.8
                width: parent.width
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                font {
                    pointSize: 70
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: gripContainer
            anchors.left: parent.left
            anchors.top: avgAccel.bottom
            anchors.bottom: accelBehavTitle.top
            width: parent.width

            color: theme.appBackgroundColor

            Rectangle {
                id: frontLeft
                anchors.left: parent.left
                anchors.top: parent.top
                width: parent.width * 0.35
                height: parent.height * 0.35
                anchors.leftMargin: parent.width * 0.1
                anchors.topMargin: parent.height * 0.1

                color: theme.tabBackgroundColor
                border.color: percToColor(vrData.tireGripFL)

                Rectangle {
                    width: parent.width * (1 - vrData.tireGripFL)
                    height: parent.height
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
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

                color: theme.tabBackgroundColor
                border.color: percToColor(vrData.tireGripFR)

                Rectangle {
                    width: parent.width * (1 - vrData.tireGripFR)
                    height: parent.height
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

                color: theme.tabBackgroundColor
                border.color: percToColor(vrData.tireGripRL)

                Rectangle {
                    width: parent.width * (1 - vrData.tireGripRL)
                    height: parent.height
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
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

                color: theme.tabBackgroundColor
                border.color: percToColor(vrData.tireGripRR)

                Rectangle {
                    width: parent.width * (1 - vrData.tireGripRR)
                    height: parent.height
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    color: percToColor(vrData.tireGripRR)
                }
            }
        }
    }

    CarInfoForAnalytics {
        id: general
        anchors.centerIn: parent
        height: parent.height
        width: parent.width * .3
    }

    UpshiftAnalytics {
        id: upShift
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height
        width: parent.width * .35
    }
}

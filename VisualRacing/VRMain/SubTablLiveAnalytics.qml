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
            text: qsTr("Upshift") + vrMainWindow.emptyString

            font {
                pointSize: 50
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
        }

        Rectangle {
            id: lastUpShiftContainer
            width: parent.width
            height: parent.height * 0.33
            anchors.left: parent.left
            anchors.top: parent.top

            color: "transparent"

            Text {
                color: theme.textColor
                text: qsTr("Last Upshift") + vrMainWindow.emptyString

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
                text: "" + vrMetrics.clutchDisengagedTime

                height: parent.height * 0.7
                width: parent.width * 0.5
                anchors.bottom: cdtLabel.top
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

            Text {
                id: cdtLabel
                color: theme.textColor
                text: qsTr("Clutch disengaged (in ms)") + vrMainWindow.emptyString

                anchors.margins: 5
                height: parent.height * 0.1
                width: parent.width * 0.5
                anchors.left: parent.left
                anchors.bottom: parent.bottom

                font {
                    pointSize: 50
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: theme.textColor
                text: "" + vrMetrics.gearChangeTime

                height: parent.height * 0.7
                width: parent.width * 0.5
                anchors.bottom: gctLabel.top
                anchors.right: parent.right

                font {
                    pointSize: 70
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: gctLabel
                color: theme.textColor
                text: qsTr("Gear change (in ms)") + vrMainWindow.emptyString

                anchors.margins: 5
                height: parent.height * 0.1
                width: parent.width * 0.5
                anchors.right: parent.right
                anchors.bottom: parent.bottom

                font {
                    pointSize: 50
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }
        }

        Rectangle {
            id: diffContainer
            width: parent.width
            anchors.left: parent.left
            anchors.top: lastUpShiftContainer.bottom
            anchors.bottom: avgUpShiftContainer.top

            color: "transparent"

            Rectangle {
                id: colorIndicator
                width: parent.width * 0.75
                height: parent.height * 0.8
                anchors.centerIn: parent
                radius: 12

                color: "transparent"

                Text {
                    text: vrMetrics.diffToAvgShiftTime >= 0 ? "+" + vrMetrics.diffToAvgShiftTime: "" + vrMetrics.diffToAvgShiftTime
                    color: theme.textColor

                    anchors.fill: parent

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

            Connections {
                target: vrMetrics
                onDiffToAvgShiftTimeChanged: diffContainer.updateColor()
                onMinClutchDisTimeChanged: diffContainer.setColorToBest()
            }

            function setColorToBest() {
                colorIndicator.color = "mediumorchid";
            }

            function updateColor() {
                if (vrMetrics.diffToAvgShiftTime === 0)
                    colorIndicator.color = "gold";
                else if (vrMetrics.diffToAvgShiftTime > 0)
                    colorIndicator.color = "red";
                else
                    colorIndicator.color = "lime";
            }
        }

        Rectangle {
            id: avgUpShiftContainer
            width: parent.width
            height: parent.height * 0.33
            anchors.left: parent.left
            anchors.bottom: upShiftTitle.top

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
                text: "" + vrMetrics.avgClutchDisTime

                height: parent.height * 0.7
                width: parent.width * 0.5
                anchors.bottom: avgCdtLabel.top
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

            Text {
                id: avgCdtLabel
                color: theme.textColor
                text: qsTr("Clutch disengaged (in ms)") + vrMainWindow.emptyString

                anchors.margins: 5
                height: parent.height * 0.1
                width: parent.width * 0.5
                anchors.left: parent.left
                anchors.bottom: parent.bottom

                font {
                    pointSize: 50
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: theme.textColor
                text: "" + vrMetrics.avgGearChangTime

                height: parent.height * 0.7
                width: parent.width * 0.5
                anchors.bottom: avgGctLabel.top
                anchors.right: parent.right

                font {
                    pointSize: 70
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: avgGctLabel
                color: theme.textColor
                text: qsTr("Gear change (in ms)") + vrMainWindow.emptyString

                anchors.margins: 5
                height: parent.height * 0.1
                width: parent.width * 0.5
                anchors.right: parent.right
                anchors.bottom: parent.bottom

                font {
                    pointSize: 50
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }
        }
    }
}

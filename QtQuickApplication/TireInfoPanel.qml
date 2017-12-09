import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    color: "#3e4244"

    Text{
        id: fuelLabel
        text: "Remaining Fuel: " + vrData.fuel.toFixed(2) + " / " + vrData.maxFuel.toFixed(2) + " L"

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: parent.width * 0.05
        anchors.topMargin: parent.height * 0.03
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 10
        }
    }

    Text{
        id: brakeBiasLabel
        text: "Brake-Bias: " + (vrData.brakeBias * 100).toFixed(1) + " %"

        anchors.left: parent.left
        anchors.top: fuelLabel.bottom
        anchors.leftMargin: parent.width * 0.05
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 10
        }
    }


    Rectangle{
        id: frontLeftWheel
        width: parent.width * 0.37
        height: parent.height * 0.18
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: parent.height * 0.2
        anchors.leftMargin: parent.width * 0.05
        color: "transparent"

        Rectangle{
            id: frontLeftDataBlock
            width: parent.width * 0.7
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
            color: "transparent"

            Column{
                Row{

                    Text {
                        text: qsTr("Pressure:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("I:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFLI.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("Wear:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: (vrData.tireWearFL * 100).toFixed(0)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("C:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFLC.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("Dirt:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("O:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFLO.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }
            }
        }

        Rectangle{
            width: parent.width * 0.23
            height: parent.height
            anchors.top: parent.top
            anchors.right: parent.right
            color: "transparent"

            Rectangle{
                id: frontLeft
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#aa2222" }
                    GradientStop { position: 0.5; color: "#22aa22" }
                    GradientStop { position: 1.0; color: "#2222aa" }
                }

            }
        }
    }

    Text{
        id: frontLeftBrakeLabel
        text: "Brake Temp.: " + "0" + " °C"

        anchors.right: frontLeftWheel.right
        anchors.top: frontLeftWheel.bottom
        anchors.topMargin: parent.height * 0.03
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 12
        }
    }


    Rectangle{
        id: frontRightWheel
        width: parent.width * 0.37
        height: parent.height * 0.18
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: parent.height * 0.2
        anchors.rightMargin: parent.width * 0.05
        color: "transparent"

        Rectangle{
            id: frontRightDataBlock
            width: parent.width * 0.7
            height: parent.height
            anchors.top: parent.top
            anchors.right: parent.right
            color: "transparent"

            Column{
                Row{
                    Text {
                        text: qsTr("I:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFRI.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("Pressure:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("C:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFRC.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("Wear:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: (vrData.tireWearFR * 100).toFixed(0)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("O:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureFRO.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("Dirt:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }
            }
        }

        Rectangle{
            width: parent.width * 0.23
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
            color: "transparent"

            Rectangle{
                id: frontRight
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#2222aa" }
                    GradientStop { position: 0.5; color: "#22aa22" }
                    GradientStop { position: 1.0; color: "#aa2222" }
                }

            }
        }
    }

    Text{
        id: frontRightBrakeLabel
        text: "Brake Temp.: " + "0" + " °C"

        anchors.left: frontRightWheel.left
        anchors.top: frontRightWheel.bottom
        anchors.topMargin: parent.height * 0.03
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 12
        }
    }


    Rectangle{
        id: rearLeftWheel
        width: parent.width * 0.37
        height: parent.height * 0.18
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: parent.height * 0.2
        anchors.leftMargin: parent.width * 0.05
        color: "transparent"

        Rectangle{
            id: rearLeftDataBlock
            width: parent.width * 0.7
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
            color: "transparent"

            Column{
                Row{

                    Text {
                        text: qsTr("Pressure:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("I:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRLI.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("Wear:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: (vrData.tireWearRL * 100).toFixed(0)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("C:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRLC.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{
                    Text {
                        text: qsTr("Dirt:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: qsTr("O:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRLO.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }
            }
        }

        Rectangle{
            width: parent.width * 0.23
            height: parent.height
            anchors.top: parent.top
            anchors.right: parent.right
            color: "transparent"

            Rectangle{
                id: rearLeft
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#aa2222" }
                    GradientStop { position: 0.5; color: "#22aa22" }
                    GradientStop { position: 1.0; color: "#2222aa" }
                }

            }
        }
    }

    Text{
        id: rearLeftBrakeLabel
        text: "Brake Temp.: " + "0" + " °C"

        anchors.right: rearLeftWheel.right
        anchors.top: rearLeftWheel.bottom
        anchors.topMargin: parent.height * 0.03
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 12
        }
    }


    Rectangle{
        id: rearRightWheel
        width: parent.width * 0.37
        height: parent.height * 0.18
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: parent.height * 0.2
        anchors.rightMargin: parent.width * 0.05
        color: "transparent"

        Rectangle{
            id: rearRightDataBlock
            width: parent.width * 0.7
            height: parent.height
            anchors.top: parent.top
            anchors.right: parent.right
            color: "transparent"

            Column{
                Row{

                    Text {
                        text: qsTr("I:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRRI.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                    Text {
                        text: qsTr("Pressure:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{

                    Text {
                        text: qsTr("C:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRRC.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                    Text {
                        text: qsTr("Wear:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: (vrData.tireWearRR * 100).toFixed(0)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }

                Row{

                    Text {
                        text: qsTr("O:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: vrData.tireTemperatureRRO.toFixed(1)
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                    Text {
                        text: qsTr("Dirt:")
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }

                    Text {
                        text: "0"
                        color: "white"
                        width: frontLeftDataBlock.width / 4
                        height: frontLeftDataBlock.height / 3
                        horizontalAlignment: Text.AlignRight + Text.width/2
                        verticalAlignment: Text.AlignVCenter
                        font {
                            pointSize: width / 6
                        }
                    }
                }
            }
        }

        Rectangle{
            width: parent.width * 0.23
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
            color: "transparent"

            Rectangle{
                id: rearRight
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#2222aa" }
                    GradientStop { position: 0.5; color: "#22aa22" }
                    GradientStop { position: 1.0; color: "#aa2222" }
                }

            }
        }
    }

    Text{
        id: rearRightBrakeLabel
        text: "Brake Temp.: " + "0" + " °C"

        anchors.left: rearRightWheel.left
        anchors.top: rearRightWheel.bottom
        anchors.topMargin: parent.height * 0.03
        width: parent.width / 4

        color: "white"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: width / 12
        }
    }
}

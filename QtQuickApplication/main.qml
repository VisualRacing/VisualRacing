import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {

    property int numberOfTabs: 4 // number of Tabs for Aligning the SettingsTab right and the "invisible" Tab
    property bool unitSystemIsMetric: true // Flag for changing the unit system in settings

    function returnVelocity(speedInKMH) {
        if(unitSystemIsMetric)
            return speedInKMH.toFixed(0);
        else
            return (speedInKMH * 0.621371).toFixed(0);
    }

    function returnTemperature(tempInCelsius) {
        if(unitSystemIsMetric)
            return tempInCelsius.toFixed(1) + " °C";
        else
            return (tempInCelsius * 1.8 + 32).toFixed(1) + " °F";
    }

    function returnPressure(pressureInBar) {
        if(unitSystemIsMetric)
            return pressureInBar.toFixed(1) + " Bar";
        else
            return (pressureInBar * 14.5038).toFixed(1) + " psi";
    }

    id: root
    visible: true
    width: 1500
    height: 800
    title: qsTr("Visual Racing")
    color: "#313537"

    minimumHeight: 500
    minimumWidth: 900

    TabView {
        id: tabView_main
        width: parent.width - 20
        height: parent.height - 40
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        currentIndex: vrMainWindow.getItsCurrentTab()

        Tab {
            id: generalTab
            title: "General"
            TabGeneral{

            }
        }

        Tab {
            id: carTab
            title: "Car"
            TabCar{

            }
        }

        Tab {
            id: timingTab
            title: "Timing"
            TabTiming{

            }
        }
        /*
        Tab {
            id: analyticsTab
            title: "Analytics"
            TabAnalytics{

            }
        }
        */
        Tab {
            id: seperatorTab
            title: ""
        }

        Tab {
            id: settingsTab
            title: "Settings"
            TabSettings{

            }
        }


        style: TabViewStyle {
            frameOverlap: 1
            tab: Rectangle {
                color: if(styleData.title === ""){"#313537"}else{styleData.selected ? "#3e4244" :"#555555"}         // all tabs with "" will be unvisible
                border.color: styleData.selected ? "#3e4244" :"#313537"                                             // border width = 1 pixel
                implicitWidth: if(styleData.title === ""){tabView_main.width - (79 * numberOfTabs)}else{80}         // text must be shorter than 80 pixels
                implicitHeight: 30
                Text {
                    id: text_label
                    anchors.centerIn: parent
                    text: styleData.title
                    color: styleData.selected ? "white" : "white"
                }
            }
        }

        // control the invisible seperator Tab
        function resetTab(){
            vrMainWindow.setItsCurrentTab(currentIndex);
            if (currentIndex == numberOfTabs-1){
                currentIndex = vrMainWindow.getItsLastTab();
            }
        }

        onCurrentIndexChanged: resetTab()                       // when Tab changes
    }

    Label{
        id: statusBar_main
        text: vrMainWindow.getItsCurrentMessageLabel()
        color: vrMainWindow.getItsCurrentMessageColor()
        font.pointSize: 10
        anchors.top: tabView_main.bottom
        anchors.topMargin: 5
        anchors.left: tabView_main.left


        Connections{
            target: vrMainWindow
            onItsCurrentMessageChanged: {
                statusBar_main.text = vrMainWindow.getItsCurrentMessageLabel()
                statusBar_main.color = vrMainWindow.getItsCurrentMessageColor()
            }
        }
    }

}

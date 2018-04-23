import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {

    property int numberOfTabs: 5 // number of Tabs for Aligning the SettingsTab right and the "invisible" Tab

    function returnVelocity(speedInKMH) {
        if(settings.unit == "Metric")
            return speedInKMH.toFixed(0);
        else
            return (speedInKMH * 0.621371).toFixed(0);
    }

    function returnTemperature(tempInCelsius) {
        if(settings.unit == "Metric")
            return tempInCelsius.toFixed(1) + qsTr(" °C");
        else
            return (tempInCelsius * 1.8 + 32).toFixed(1) + qsTr(" °F");
    }

    function returnPressure(pressureInBar) {
        if(settings.unit == "Metric")
            return pressureInBar.toFixed(1) + qsTr(" Bar");
        else
            return (pressureInBar * 14.5038).toFixed(1) + qsTr(" psi");
    }

    /* Tire temperature to color conversion */
    function tempToColor(t) { // TODO: Refactor.
        var cold = 60;
        var low = 75;
        var high = 85;
        var hot = 100;

        if (t < cold)
            return "#0000FF";
        else if (t > low && t < high)
            return "#00FF00";
        else if (t > hot)
            return "#FF0000";

        if(t >= cold && t <= low) {
            var p = (t - cold)/(low - cold);

            var g = parseInt((0xFF * p).toFixed(0)).toString(16);
            var b = parseInt((0xFF * (1 - p)).toFixed(0)).toString(16);

            return "#00" + (g.length < 2 ? "0" + g : g) + (b.length < 2 ? "0" + b : b);

        } else if (t >= high && t <= hot) {
            var p = (t - high)/(hot - high);

            var r = parseInt((0xFF * p).toFixed(0)).toString(16);
            var g = parseInt((0xFF * (1 - p)).toFixed(0)).toString(16);

            return "#" + (r.length < 2 ? "0" + r : r) + (g.length < 2 ? "0" + g : g) + "00";
        }

        return "white";
    }

    /* Convert a laptime in s to a string */
    function lapTimeToString(time) {
        if (time <= 0.0)
            return "--:--.---"

        var min = Math.floor(time / 60);
        var sec = time % 60;

        return (min < 10 ? "0" : "") + min + ":" + (sec < 10 ? "0" : "") + sec.toFixed(3);
    }

    function sectorTimeToString(time) { // TODO: Use in lapTimeToString()?
        if (time <= 0.0)
            return "--.---"

        return (time < 10 ? "0" : "") + time.toFixed(3);
    }

    //
    // Main window
    //

    id: root
    visible: true
    width: 1500
    height: 800
    title: qsTr("Visual Racing")
    color: theme.appBackgroundColor

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
            title: qsTr("General")
            TabGeneral{

            }
        }

        Tab {
            id: carTab
            title: qsTr("Car")
            TabCar{

            }
        }

        Tab {
            id: timingTab
            title: qsTr("Timing")
            TabTiming{

            }
        }

        Tab {
            id: analyticsTab
            title: qsTr("Analytics")
            TabAnalytics{

            }
        }

        Tab {
            id: seperatorTab
            title: ""
        }

        Tab {
            id: settingsTab
            title: qsTr("Settings")
            TabSettings{

            }
        }


        style: TabViewStyle {
            frameOverlap: 1
            tab: Rectangle {
                color: if(styleData.title === ""){theme.appBackgroundColor}else{styleData.selected ? theme.tabBackgroundColor : theme.tabInactiveColor} // all tabs with "" will be invisible
                border.color: styleData.selected ? theme.tabBackgroundColor : theme.appBackgroundColor  // border width = 1 pixel
                implicitWidth: styleData.title === "" ? tabView_main.width - (99 * numberOfTabs) : 100
                implicitHeight: 30
                Text {
                    id: text_label
                    anchors.centerIn: parent
                    text: styleData.title
                    color: styleData.selected ? theme.textColor : theme.textColor
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

        onCurrentIndexChanged: resetTab() // when Tab changes
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

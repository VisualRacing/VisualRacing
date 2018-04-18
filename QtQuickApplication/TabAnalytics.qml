import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle{
    color: "#3e4244"

    TabView {
        id: tabView_Analytics
        width: parent.width - 10
        height: parent.height - 10
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        currentIndex: 0

        Tab {
            id: liveAnalyticsTab
            title: qsTr("Live")
            SubTablLiveAnalytics{

            }
        }

        style: TabViewStyle {
            frameOverlap: 1
            tab: Rectangle {
                color: styleData.selected ? "#313537" : "#555555"
                implicitWidth: 80
                implicitHeight: 30

                Text {
                    id: text_label
                    anchors.centerIn: parent
                    text: styleData.title
                    color: "white"
                }
            }
        }

    }
    Button {
        implicitWidth: 80
        implicitHeight: 30
        anchors.left: tabView_Analytics.left
        anchors.leftMargin: (tabView_Analytics.currentIndex + 1) * 80
        anchors.top: tabView_Analytics.top

        Rectangle {
            id: addButtonRect
            anchors.fill: parent
            color: "#555555"
            Text {
                id: addButtonText
                anchors.centerIn: parent
                text: qsTr("+")
                color: "white"
            }
        }

        onClicked: addNewTab()
        onHoveredChanged: addButtonRect.color = (hovered ? "#666666" : "#555555")

        function addNewTab(){
            console.log("here can stored data get loaded")
        }
    }
}

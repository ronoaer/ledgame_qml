import QtQuick 2.15
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Window {
    id: root
    visible: true
    width: 200
    height: 300

    ColumnLayout {
//        anchors.centerIn: parent
//        anchors.leftMargin: 100


        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        //anchors.horizontalCenter: parrent.horizontalCenter

        spacing: 10

        LedLabels{
            id: labels
            height: 60
            Layout.alignment: Qt.AlignHCenter
        }

        LedButtons{
            id: buttons
            height: 80
            Layout.alignment: Qt.AlignHCenter
        }

    }

    Component.onCompleted: {
        LedGameUI.UpdateLedsColor.connect(labels.updateColor)
        LedGameUI.UpdateButtonText.connect(buttons.updateText)
    }
}

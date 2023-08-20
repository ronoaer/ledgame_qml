import QtQuick 2.15
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Window {
    id: root
    visible: true
    width: 400
    height: 300

    Item {
        id: test
        LedLabels{
            id: labels
            anchors.top:  parent.top
            anchors.left: parent.left
            height: 60
        }

        LedButtons{
            id: buttons
            anchors.top:  labels.bottom
            anchors.left: parent.left
            height: 80
        }
    }

    Component.onCompleted: {
        LedGameUI.UpdateLedsColor.connect(labels.updateColor)
        LedGameUI.UpdateButtonText.connect(buttons.updateText)

        LedGameUI.initializeButtons();
    }
}

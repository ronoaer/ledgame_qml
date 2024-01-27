import QtQuick 2.1
import QtQuick.Controls 2.1

Button {
    id: root

    property string hoveredColor: "#C1C2C5"
    property string defaultColor: "#D7D8DB"
    property string pressedColor: "#979799"

    property string textColor: "#0E0E11"

    property string borderColor: "#D7D8DB"
    property int borderWidth: 1

    property string title: ""
    property int buttonIndex: 0

    implicitHeight: 40
    implicitWidth: implicitHeight

    hoverEnabled: true

    text: title

    background: Rectangle {
        id: backgroundx
        anchors.fill: parent
        radius: 16
        color: {
            if (root.pressed) {
                return pressedColor
            }

            return root.hovered ? hoveredColor : defaultColor
        }
        border.color: borderColor
        border.width: borderWidth

        Behavior on color {
            PropertyAnimation { duration: 200 }
        }
    }

    onClicked: {
        LedGameUI.onButtonClicked(title);
    }

    MouseArea {
        anchors.fill: background
        enabled: false
        cursorShape: Qt.PointingHandCursor
    }
}

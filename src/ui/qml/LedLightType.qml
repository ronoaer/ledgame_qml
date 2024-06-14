import QtQuick 2.1

Item {
    id: root

    property string ledColor
    property string ledName
    property string borderColor: "#D7D8DB"
    property int borderWidth: 1

    Rectangle {
        id: background

        anchors.centerIn: parent
        border.color: borderColor
        border.width: borderWidth

        implicitHeight: 40
        implicitWidth: implicitHeight

        radius: width/2
        color: ledColor

        Text {
            anchors.centerIn: parent
            text: ledName
        }
    }

}

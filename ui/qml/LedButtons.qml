import QtQuick 2.1
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 300
    height: 40

    GridView {
        id: buttons
        anchors.fill: parent
        cellWidth: parent.width / 3
        model: ButtonModel

        delegate: LedButtonType {
            id: button
            width: 40
            height: 40
            title: buttonTexta
            buttonIndex: buttonIndexa

            background: Rectangle {
                border.color: button.hovered ? "#17a81a" : "#aba9b2"
                border.width: 1
                radius: 2
                opacity: enabled ? 1 : 0.3
                color: "#dcdcdc"
            }
        }
    }
}

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

        delegate: Button {
            id: button
            width: 40
            height: 40

            Text {
                id: buttonTextId
                anchors.centerIn: parent
                text: model.ButtonText
                color: "black"
            }

            onClicked: {
                LGController.onButtonClicked(buttonTextId.text);
            }
        }
    }
}

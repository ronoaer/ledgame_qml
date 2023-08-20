import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 400
    height: 200

    ListModel {
        id: ledsModel

        ListElement{title: "A"}
        ListElement{title: "B"}
        ListElement{title: "C"}
    }

    GridView {
        id: buttons
        width: parent.width
        height: parent.height

        model: ledsModel

        delegate: Rectangle {
            width: 40
            height: 40
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: title
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    LedGameUI.onButtonClicked(title);
                }
            }
        }
    }

    function updateText(index, key) {
       ledsModel.get(index).title = key;
    }
}

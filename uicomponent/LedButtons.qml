import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 300
    height: 40

    ListModel {
        id: ledsModel
    }

    GridView {
        id: buttons
        anchors.fill: parent
        cellWidth: parent.width / 3
        model: ledsModel

        delegate: Button {
            id: button
            width: 40
            height: 40
            text: title

            background: Rectangle {
                border.color: button.down ? "#17a81a" : "#21be2b"
                border.width: 1
                radius: 2
            }


            onClicked: {
                LedGameUI.onButtonClicked(title);
            }
        }
    }

    Component.onCompleted: {
        var keyArray = ["A", "B", "C"]
        var keyIndex = Math.floor(Math.random() * 3)

        console.log(keyIndex)

        for (var i=0; i<3; i++) {
            var data = {'title': keyArray[keyIndex]};
            ledsModel.append(data)

            keyIndex++
            if (keyIndex > 2) {
                keyIndex = 0
            }
        }
    }

    function updateText(index, key) {
       ledsModel.get(index).title = key;
    }
}

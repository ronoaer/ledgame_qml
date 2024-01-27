import QtQuick 2.1
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 300
    height: 40

<<<<<<< HEAD
=======
    ListModel {
        id: ledsModel
    }

>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
    GridView {
        id: buttons
        anchors.fill: parent
        cellWidth: parent.width / 3
<<<<<<< HEAD
        model: ButtonModel

        delegate: LedButtonType {
            id: button
            width: 40
            height: 40
            title: buttonTexta
            buttonIndex: buttonIndexa
=======
        model: ledsModel

        delegate: Button {
            id: button
            width: 40
            height: 40
            text: title
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a

            background: Rectangle {
                border.color: button.hovered ? "#17a81a" : "#aba9b2"
                border.width: 1
                radius: 2
                opacity: enabled ? 1 : 0.3
                color: "#dcdcdc"
            }
<<<<<<< HEAD
        }
    }
=======


            onClicked: {
                LedGameUI.onButtonClicked(title);
            }
        }
    }

    Component.onCompleted: {
        var keyArray = ["A", "B", "C"]
        var keyIndex = Math.floor(Math.random() * 3)

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
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
}

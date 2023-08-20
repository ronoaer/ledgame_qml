import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 400
    height: 200

    ListModel {
        id: ledsModel
        ListElement { name: "Led 1"
            backgroundx: "red"
        }

        ListElement { name: "Led 2"
            backgroundx: "yellow"
        }

        ListElement { name: "Led 3"
            backgroundx: "red"
        }
    }


    GridView {
        id: labels

        width: parent.width
        height: parent.height
        model: ledsModel

        delegate: Rectangle {
            width: 40
            height: 40
            color: backgroundx

            Text {
                anchors.centerIn: parent
                text: name
            }
        }
    }

    function updateColor(press_index, color) {
        var count = 0;

        for (var i=ledsModel.count-1; i>=0; i--) {
            var curcolor = ledsModel.get(i).backgroundx;
            ledsModel.get(i).backgroundx = color;
            color = curcolor;

            count++;
            if (count >= press_index) {
                break;
            }
        }
    }
}


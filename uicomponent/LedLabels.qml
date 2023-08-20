import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 400
    height: 200

    ListModel {
        id: ledsModel
    }


    GridView {
        id: labels

        width: parent.width
        height: parent.height
        model: ledsModel

        delegate: Rectangle {
            width: 40
            height: 40
            color: bg_color

            Text {
                anchors.centerIn: parent
                text: name
            }
        }
    }

    Component.onCompleted: {
        for (var i=0; i<3; i++) {
            var data = {'name': qsTr("Led ") + (i+1).toString(), 'bg_color': "red"};
            ledsModel.append(data)
        }
    }

    function updateColor(press_index, color) {
        var count = 0;

        for (var i=ledsModel.count-1; i>=0; i--) {
            var curcolor = ledsModel.get(i).bg_color;
            ledsModel.get(i).bg_color = color;
            color = curcolor;

            count++;
            if (count >= press_index) {
                break;
            }
        }
    }
}

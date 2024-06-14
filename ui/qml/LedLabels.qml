import QtQuick 2.1
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: root

    width: 300
    height: 40

    GridView {
        id: labels
        anchors.fill: parent
        model: ledsModel

        cellWidth: parent.width / 3

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
        var colorArray = ["#ff0000", "#ffff00", "#00ff00"]

        for (var i=0; i<3; i++) {
            var colorIndex = Math.floor(Math.random() * 3)

            var data = {'name': qsTr("Led ") + (i+1).toString(), 'bg_color': colorArray[colorIndex]};
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


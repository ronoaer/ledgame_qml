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
        model: LedModel

        cellWidth: parent.width / 3

        delegate: LedLightType {
           width: 40
           height: 40
           ledColor: model.LedColor
           ledName: model.LedName
        }
    }
}


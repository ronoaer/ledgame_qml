import QtQuick 2.1
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Window {
    id: root
    visible: true
    width: 450
    height: 300
    minimumHeight: 100
    minimumWidth: 150

    ColumnLayout {
        anchors.centerIn: parent

        LedLabels{
            id: labels
            height: 60
        }

        LedButtons{
            id: buttons
            height: 80
        }
    }
}

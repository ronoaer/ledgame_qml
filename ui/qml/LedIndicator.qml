import QtQuick 2.1

Item {
    id: root

    property string indicatorColor: "green"

    Rectangle {
        width: 50
        height: 50
        radius: width / 2

        color: indicatorColor
    }
}

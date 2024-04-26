import QtQuick

Item {
    id: histogram

    implicitWidth: parent ? parent.width : 0
    implicitHeight: parent ? parent.height : 0

    Image {
        id: backgroundImage

        anchors.fill: parent
        source: "qrc:/img/assets/hist-background.png"
    }
}

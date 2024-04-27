import QtQuick
import QtQuick.Controls

import Hist.UI 1.0

ProgressBar {
    id: hProgressBar

    background: Rectangle {
        anchors.fill: hProgressBar
        border.width: 0
        color: Styles.primary_c
        radius: Styles.standardRadius
    }

    contentItem: Item {
        implicitWidth: hProgressBar.width
        implicitHeight: hProgressBar.height

        Rectangle {
            width: hProgressBar.visualPosition * parent.width
            height: parent.height
            radius: Styles.standardRadius
            color: Styles.gray_c
        }
    }
}

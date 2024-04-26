import QtQuick
import QtQuick.Controls

import Hist.Utility 1.0

Button {
    id: hButton

    font.pixelSize: Styles.defaultButtonFontSize

    background: Rectangle {
        implicitWidth: Styles.defaultButtonWidth
        implicitHeight: Styles.defaultButtonHeight
        border.width: 0
        color: hButton.down ? Styles.secondary_c : Styles.defaultButton_c
        radius: Styles.standardRadius
    }

    contentItem: Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: hButton.text
        font: hButton.font
        color: Styles.white_c
    }
}

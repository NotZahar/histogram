import QtQuick
import QtQuick.Controls

import Hist.UI 1.0

Button {
    id: hButton

    property string backgroundColor: Styles.defaultButton_c

    font.pixelSize: Styles.defaultButtonFontSize

    background: Rectangle {
        implicitWidth: Styles.defaultButtonWidth
        implicitHeight: Styles.defaultButtonHeight
        border.width: 0
        color: {
            if (hButton.enabled)
                return hButton.down ? Styles.secondary_c : hButton.backgroundColor
            return Styles.black_c
        }
        radius: Styles.standardRadius
    }

    contentItem: Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: hButton.text
        font: hButton.font
        color: hButton.enabled ? Styles.white_c : Styles.gray_c
    }
}

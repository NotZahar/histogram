import QtQuick

import Hist.UI 1.0

Item {
    id: histogram

    property alias topLabelText: topLabel.text
    property alias bottomLabelText: bottomLabel.text
    property alias labelMaxText: labelTextMetrics.text

    implicitWidth: parent ? parent.width : 0
    implicitHeight: parent ? parent.height : 0

    Image {
        id: backgroundImage

        anchors.fill: parent
        source: "qrc:/img/assets/hist-background.png"
    }

    Item {
        id: histogramContent

        anchors {
            fill: parent
            margins: Styles.defaultSpacing
        }

        Item {
            id: labelColumn

            width: labelTextMetrics.width
            height: parent.height

            TextMetrics {
                id: labelTextMetrics

                font.pixelSize: Styles.mediumFontSize
                text: "999999"
            }

            Text {
                id: topLabel

                anchors {
                    top: parent.top
                    right: parent.right
                }
                font.pixelSize: Styles.mediumFontSize
                color: Styles.white_c
            }

            Text {
                id: bottomLabel

                anchors {
                    bottom: parent.bottom
                    right: parent.right
                }
                font.pixelSize: Styles.mediumFontSize
                color: Styles.white_c
            }
        }

        Row {
            id: columnsRow

            readonly property int _modelData: 10
            readonly property real _columnWidth: (parent.width - labelColumn.width - Styles.defaultSpacing * columnsRow._modelData)
                                                 / columnsRow._modelData

            anchors {
                left: labelColumn.right
                right: parent.right
                leftMargin: Styles.defaultSpacing
            }
            spacing: Styles.defaultSpacing

            Repeater {
                id: columnsRepeater

                model: columnsRow._modelData

                Rectangle {
                    width: columnsRow._columnWidth
                    height: histogramContent.height
                    color: Styles.green_c
                    radius: Styles.standardRadius
                }
            }
        }
    }
}

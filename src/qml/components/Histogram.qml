import QtQuick
import QtQml.Models

import Hist.UI 1.0

Item {
    id: histogram

    property alias topLabelValue: topLabel.labelValue
    property alias bottomLabelValue: bottomLabel.labelValue
    property alias labelMaxText: labelTextMetrics.text
    property alias dataModel: columnsModel

    property int firstNVisible: 3

    implicitWidth: parent ? parent.width : 0
    implicitHeight: parent ? parent.height : 0

    Image {
        id: backgroundImage

        anchors.fill: parent
        source: "qrc:/img/assets/hist-background.png"
    }

    Item {
        id: histogramContent

        readonly property real _topItemsHeight: histogramContent.height - labelTextMetrics.height

        anchors {
            fill: parent
            margins: Styles.defaultSpacing
        }

        ListModel {
            id: columnsModel
        }

        Item {
            id: labelColumn

            width: labelTextMetrics.width
            height: histogramContent._topItemsHeight

            TextMetrics {
                id: labelTextMetrics

                font.pixelSize: Styles.mediumFontSize
                text: "999999"
            }

            Text {
                id: topLabel

                property int labelValue: 1000 // 0

                anchors {
                    top: parent.top
                    right: parent.right
                }
                font.pixelSize: Styles.mediumFontSize
                text: topLabel.labelValue
                color: Styles.white_c
            }

            Text {
                id: bottomLabel

                property int labelValue: 0

                anchors {
                    bottom: parent.bottom
                    right: parent.right
                }
                font.pixelSize: Styles.mediumFontSize
                text: bottomLabel.labelValue
                color: Styles.white_c
            }
        }

        Row {
            id: columnsRow

            readonly property int _numberOfColumns: columnsModel.count
            readonly property real _columnWidth: (parent.width - labelColumn.width - Styles.defaultSpacing * columnsRow._numberOfColumns)
                                                 / columnsRow._numberOfColumns

            anchors {
                left: labelColumn.right
                right: parent.right
                leftMargin: Styles.defaultSpacing
            }
            height: histogramContent._topItemsHeight
            spacing: Styles.defaultSpacing

            Repeater {
                id: columnsRepeater

                model: columnsModel

                Rectangle {
                    id: columnDelegate

                    required property int quantity
                    required property string word

                    width: columnsRow._columnWidth
                    height: (columnDelegate.quantity / topLabel.labelValue) * histogramContent._topItemsHeight
                    anchors.bottom: parent.bottom
                    color: Styles.green_c
                    radius: Styles.standardRadius

                    Text {
                        id: wordLabel

                        anchors.centerIn: parent
                        font.pixelSize: Styles.mediumFontSize
                        text: columnDelegate.word.substring(0, histogram.firstNVisible)
                        color: Styles.black_c
                        wrapMode: Text.WrapAnywhere
                    }

                    Text {
                        id: quantityLabel

                        anchors {
                            top: parent.bottom
                            topMargin: Styles.smallSpacing
                            horizontalCenter: parent.horizontalCenter
                        }
                        font.pixelSize: Styles.smallFontSize
                        text: columnDelegate.quantity
                        color: Styles.white_c
                    }
                }
            }
        }

        Component.onCompleted: {
            columnsModel.append({ "quantity": 100, "word": "abcd" })
            columnsModel.append({ "quantity": 100, "word": "abcd" })
            columnsModel.append({ "quantity": 40, "word": "abcd" })
            columnsModel.append({ "quantity": 190, "word": "abcd" })
            columnsModel.append({ "quantity": 500, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 990, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 900, "word": "abcd" })
            columnsModel.append({ "quantity": 800, "word": "abcd" })
        }
    }
}

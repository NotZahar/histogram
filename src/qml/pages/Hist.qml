import QtQuick
import Qt5Compat.GraphicalEffects

import Hist.Utility 1.0

import "../components" as HistComponents

Item {
    id: histogramPage

    implicitWidth: parent ? parent.width : 0
    implicitHeight: parent ? parent.height : 0

    Item {
        id: contentContainer

        anchors {
            fill: parent
            margins: Styles.standardMargin
        }

        Item {
            id: histogramContainer

            width: parent.width
            anchors {
                top: parent.top
                bottom: controlContainer.top
                bottomMargin: Styles.defaultSpacing
            }

            HistComponents.Histogram {
                id: histogram

                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: radiusMask
                }
            }

            Rectangle {
                id: radiusMask

                visible: false
                anchors.fill: parent
                radius: Styles.standardRadius
            }
        }

        Column {
            id: controlContainer

            width: parent.width
            anchors.bottom: parent.bottom
            spacing: Styles.defaultSpacing

            Item {
                id: btnsRow

                width: parent.width
                height: Styles.defaultButtonHeight

                HistComponents.HButton {
                    id: openBtn

                    text: "Открыть" // TODO

                    onClicked: console.log("1") // TODO
                }

                HistComponents.HButton {
                    id: startBtn

                    anchors {
                        left: openBtn.right
                        leftMargin: Styles.defaultSpacing
                    }
                    text: "Старт" // TODO

                    onClicked: console.log("2") // TODO
                }

                HistComponents.HButton {
                    id: cancelBtn

                    anchors.right: parent.right
                    text: "Отмена" // TODO

                    onClicked: console.log("3") // TODO
                }
            }

            HistComponents.HProgressBar {
                id: readProgressBar

                width: parent.width
                height: Styles.defaultButtonHeight
                value: 0.5 // TODO
            }
        }
    }
}

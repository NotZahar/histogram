import QtQuick
import Qt5Compat.GraphicalEffects

import Hist.UI 1.0
import Hist.Control 1.0

import "../components" as HistComponents
import "../components/controllers" as HistControllers

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

                Row {
                    id: leftButtonsRow

                    spacing: Styles.defaultSpacing

                    HistComponents.HButton {
                        id: openBtn

                        enabled: HistPageController.openEnabled
                        text: Messages.open_btn
                        backgroundColor: Styles.darkGray_c

                        onClicked: fsDialog.open()
                    }

                    HistComponents.HButton {
                        id: startBtn

                        enabled: HistPageController.startEnabled
                        text: Messages.start_btn

                        onClicked: HistPageController.onStarted()
                    }
                }

                HistComponents.HButton {
                    id: cancelBtn

                    enabled: HistPageController.cancelEnabled
                    anchors.right: parent.right
                    text: Messages.cancel_btn
                    backgroundColor: Styles.pink_c

                    onClicked: HistPageController.onCanceled()
                }
            }

            HistComponents.HProgressBar {
                id: readProgressBar

                value: HistPageController.processProgressValue
                width: parent.width
                height: Styles.defaultButtonHeight
            }
        }
    }

    HistControllers.HFileSystemDialogControl {
        id: fsDialog

        onSelectedFileChanged: {
            HistPageController.onFileSelected(fsDialog.selectedFile)
        }
    }
}

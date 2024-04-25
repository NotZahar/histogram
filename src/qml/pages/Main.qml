import QtQuick
import QtQuick.Controls

import H_Utility 1.0

Page {
    id: mainWindow

    readonly property real _initialWidth: 900
    readonly property real _initialHeight: 600

    width: mainWindow._initialWidth
    height: mainWindow._initialHeight

    Rectangle {
        id: backgroundItemColor

        anchors.fill: parent
        color: Styles.background_c
    }

    StackView {
        id: navigationStack

        anchors.fill: parent
        initialItem: mainView
    }

    Component {
       id: mainView

       Row {
           spacing: 10

           Button {
               text: "Push"
               onClicked: navigationStack.push(mainView)
           }

           Button {
               text: "Pop"
               enabled: navigationStack.depth > 1
               onClicked: navigationStack.pop()

           }

           Text {
               text: navigationStack.depth
           }
       }
    }
}

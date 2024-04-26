import QtQuick
import QtQuick.Controls

import Hist.Utility 1.0
import Hist.Navigation 1.0

Page {
    id: mainPage

    readonly property real _initialWidth: 900
    readonly property real _initialHeight: 600

    width: mainPage._initialWidth
    height: mainPage._initialHeight

    Rectangle {
        id: backgroundItemColor

        anchors.fill: parent
        color: Styles.background_c
    }

    Component {
        id: startComponent

        Item {
            width: mainPage.width
            height: mainPage.height
        }
    }

    StackView {
        id: pageNavigationStack

        anchors.fill: parent
        initialItem: startComponent
        pushEnter: pageTransition
        pushExit: pageTransition
        popEnter: pageTransition
        popExit: pageTransition
    }

    Transition {
        id: pageTransition

        PropertyAnimation {
            property: "opacity"
            from: 0
            to: 1
            duration: 200
        }
    }

    Connections {
        target: NavigationService

        function onChangePage(pagePath: string) {
            pageNavigationStack.push(pagePath)
        }
    }
}

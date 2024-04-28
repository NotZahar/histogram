import QtQuick
import QtQuick.Dialogs
import QtCore

FileDialog {
    id: fileDialog

    currentFolder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
    nameFilters: ["Text files (*.txt)"]
}


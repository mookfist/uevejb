import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.LocalStorage 2.0
import "qrc:///assets/ui/settings.js" as Settings


ApplicationWindow {
    id: optionsWindow

    width: 400
    height: 400

    modality: Qt.WindowModal
    title: "Unofficial EVE Jukebox - Options"

    FileDialog {
        id: eveLogsDir
        title: "Choose Logs Dir"
        selectFolder: true
        selectMultiple: false

        onAccepted: {
            console.log(fileUrl);
            eveLogsDirValue.text = fileUrl;
        }
    }

    GridLayout {
        columns: 2
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 10
        columnSpacing: 10

        Label {
            text: "EVE Logs Directory"
            Layout.fillWidth: true
        }

        Grid {
            Layout.fillWidth: true
            columns: 2
            TextField {

                id: eveLogsDirValue
            }
            Button {
                text: "Browse"
                onClicked: {
                    eveLogsDir.open()
                }
            }

            Button {
                text: "OK"
                onClicked: {
                    Settings.set("eveLogsDir", eveLogsDirValue.text);
                    optionsWindow.close();
                }
            }
        }
    }
}

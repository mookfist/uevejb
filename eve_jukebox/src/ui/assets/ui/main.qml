//import related modules
import QtQuick 2.3
import QtQuick.Controls 1.3
import QtQuick.Window 2.0
import QtQuick.LocalStorage 2.0
import "qrc:///assets/ui/settings.js" as Settings

//window containing the application
ApplicationWindow {

    id: mainWindow
    //title of the application
    title: qsTr("Unofficial EVE Jukebox")
    width: 640
    height: 480
    visible: true

    signal qmlSignal(string msg)

    Component.onCompleted: {
        console.log("window loaded");

        console.log(Settings.get("eveLogsDir"));
    }

    FontLoader {
        id: eveSansNeueRegular
        source: "qrc:///assets/fonts/evesansneue-regular.ttf"
    }

    FontLoader {
        id: eveSansNeueBold
        source: "qrc:///assets/fonts/evesansneue-bold.ttf"
    }

    FontLoader {
        id: eveSansNeueItalic
        source: "qrc:///assets/fonts/evesansneue-italic.ttf"
    }

    FontLoader {
        id: eveSansNeueBoldItalic
        source: "qrc:///assets/fonts/evesansneue-bolditalic.ttf"
    }

    //menu containing two menu items
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Import Playist...")
            }
            MenuItem {
                text: qsTr("Create New Playlist")
            }
            MenuSeparator {

            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Settings")
            MenuItem {
                text: qsTr("Options")
                onTriggered: {
                    var component = Qt.createComponent("qrc:///assets/ui/options.qml");
                    var win = component.createObject(mainWindow);
                    win.show();
                }
            }
            MenuSeparator {}
            MenuItem {
                id: menuDiscoverCharacter
                text: qsTr("Discover Characters")
                onTriggered: mainWindow.qmlSignal(Settings.get("eveLogsDir"));
            }
        }
    }

    Column {

        spacing: 0

        // Header
        Rectangle {
            id: header
            width: 640
            height: 80

            Image {
                source: "qrc:///assets/auralogo.png"
                width: 80
                height: 80
            }

            Label {
                id: charlabel
                text: "Aura the AI"
                x: 85
                y: 5
                font.family: "Eve Sans Neue"
                font.pointSize: 16
                color: "#9FA0A3"
            }

            Label {
                id: coordsLabel
                text: "<span style=\"font-size: 11pt\">System Label</span> &lt; <span style=\"font-size: 9pt\">Region Label</span>"
                textFormat: Text.RichText
                font.family: "Eve Sans Neue"
                color: "#D4D4D5"
                x: 85
                y: 35
            }

            Label {
                id: dockingLabel
                text: "Undocked"
                font.family: "Eve Sans Neue"
                font.pointSize: 8
                color: "#CA5B5B"
                x: 85
                y: 58
            }

            color: "#03060C"
        }

        //Content Area
        Rectangle {
            color: "#141518"
            width: 640
            height: 100

            Grid {
                columns: 2
                spacing: 3
                Image {
                    id: volumeIcon
                    source: "qrc:///assets/icons/volume-1.png"
                    height: 16
                    width: 16
                }

                Slider {
                    value: 0.5
                    onValueChanged: {
                        if (value > 0.3 && value < 0.8) {
                            volumeIcon.source = "qrc:///assets/icons/volume-2.png"
                        } else if (value < 0.3) {
                            volumeIcon.source = "qrc:///assets/icons/volume-1.png"
                        } else if (value === 1) {
                            volumeIcon.source = "qrc:///assets/icons/volume-3.png"
                        }
                    }
                }
            }
        }
    }
}

import QtQuick
import Serial 1.0

Window {

    id: window
    width: 800
    height: 480
    visible: true
    title: qsTr("Serial Communication")
    color: "black"

    Serial{
        id: serial
    }
    Component.onCompleted : {
            serial.startReading()
        }

    Text{
        anchors.centerIn: parent
        text: serial.data
        font.bold: true
        font.pixelSize: 20
        font.family:  "Helvetica"
        color: "white"
    }

}

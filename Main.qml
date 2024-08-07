import QtQuick
import QtQuick.Layouts
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
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 50
    Text{
        text: "Reading Serial Data"
        font.family:  "Helvetica"
        color: "white"
        font.bold: true
        font.pixelSize: 16
        Layout.alignment: Qt.AlignHCenter
    }

    Text{

        text: serial.data
        font.pixelSize: 18
        font.family:  "Helvetica"
        color: "white"
        Layout.alignment: Qt.AlignHCenter
    }
    }

}

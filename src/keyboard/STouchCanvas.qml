import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import s.keyboard.backend 1.0

Window {
    id: root
    visible: true
    width: 480; height: 800
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    SBackendKeyboard {
        id: backend

        onDisplayChanged: {
            //labelValue.text = backend.display
            console.log("Completed onDisplayChanged!")
        }
        onTitleChanged: {
            //labelTitle.text = backend.title
            console.log("Completed onTitleChanged!")
        }
    }

    Rectangle {
        anchors.fill: mainLayout
        border.color: "black"
        color: "black"
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent

        // M1>>
        ColumnLayout {
            id: topLayout
            Layout.fillHeight: true
            Layout.fillWidth: true

            RowLayout {
                id: displayLayout
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    margins: 10
                }

                Button {
                    id: buttonClosed
                    width: 80
                    height: 80
                    font.pixelSize: 40
                    anchors {
                        left: parent.left
                    }
                    background: Rectangle {
                        color: "transparent"
                    }

                    text: "\u292B"

                    onReleased: {
                        root.close()
                    }
                }

                Label {
                    id: labelValue
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 30
                    color: "white"
                    text: backend.display
                }

                Button {
                    id: buttonAccept
                    width: 80
                    height: 80
                    font.pixelSize: 50
                    anchors {
                        right: parent.right
                    }
                    background: Rectangle {
                        color: "transparent"
                    }

                    text: "\u2713"
                }
            }

            Label {
                id: labelTitle
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 21
                color: "white"
                text: backend.title
            }
        }
        // <<M1

        // M2>>
        ColumnLayout {
            id: centerLayout
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter

            Rectangle {
                anchors.fill: canvas
                Layout.preferredWidth: 400
                Layout.preferredHeight: 400
                border.color: canvas.colorBackground
                color: canvas.colorBackground
            }

            Canvas {
                id: canvas
                anchors.fill: parent

                property real hue: 0
                property real lastX
                property real lastY
                property bool requestBlank: false
                property color colorPen: "black"
                property color colorBackground: "white"

                // M21>>
                Timer {
                    id: blankTimer
                    interval: 500
                    repeat: false
                    onTriggered: {
                        canvas.requestBlank = true
                        canvas.requestPaint()
                    }
                }
                // <<M21

                onPaint: {
                    var context = getContext('2d')
                    context.strokeStyle = canvas.colorPen
                    context.lineWidth = 10
                    context.shadowColor = canvas.colorPen
                    context.shadowBlur = 8;
                    context.beginPath()
                    context.moveTo(lastX, lastY)
                    lastX = area.mouseX
                    lastY = area.mouseY
                    context.lineTo(lastX, lastY)
                    context.stroke()

                    if (requestBlank) {
                        saveCanvas();
                        //getCanvas();
                        blankCanvas(context)
                        requestBlank = false
                    }
                }

                MouseArea {
                    id: area
                    anchors.fill: parent
                    onPressed: {
                        blankTimer.stop()
                        canvas.lastX = mouseX
                        canvas.lastY = mouseY
                    }
                    onReleased: blankTimer.running ? blankTimer.restart() : blankTimer.start()
                    onPositionChanged: canvas.requestPaint()
                }

                function getCanvas() {
                    var url = canvas.toDataURL('image/png')
                    backend.url = url
                }

                function saveCanvas() {
                    canvas.save("/etc/sentenz/config/neuron/mnist/number.bmp")
                    backend.url = ""
                }

//                function loadCanvas() {
//                    loadImage(image)
//                }

                function blankCanvas(context) {
                    context.fillStyle = canvas.colorBackground
                    context.fillRect(0, 0, canvas.width, canvas.height)
                }
            }
            // <<M2
        }
    }
}


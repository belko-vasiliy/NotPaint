import QtQuick 2.13
import QtQuick.Controls 2.5
import Painter 1.0
import EButtonType 1.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property string x_text
    property string y_text
    property string enum_text
    property string qmlFileName

    Item {
        id: isMousePressed
        property var value: false
    }

    Connections {
        target: iFile
        onSendToQml : { image.source = text}
    }

    ToolBar {
        id: mainToolBar
        RowLayout {
            id: layout
            anchors.fill: parent
            spacing: 6

            ToolButton {
                MenuBar {
                    id: menuFile
                    Menu {
                        title: qsTr("&Menu")
                        MenuItem {
                            text: "New"
                            //onClicked: painter.openNew()
                        }
                        MenuItem {
                            text: "Open"
                            //onClicked: painter.openFile()
                            onClicked: iFile.getFromQml("open")
                        }
                        MenuItem {
                            text: "Save"
                            //onClicked: painter.openSave()
                        }
                    }
                }
            }
            ToolButton {
                Image {
                    source: "T_Icon_Pencil.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    //anchors.margins: 2
                    //anchors.bottomMargin:10
                }
                onPressed: painter.setBtype(EButtonType.PENCIL)
            }
            ToolButton {
                Image {
                    source: "T_Icon_Line.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    //anchors.margins: 2
                    //anchors.bottomMargin:10
                }
                onPressed: painter.setBtype(EButtonType.LINE)
            }
            ToolButton {
                Image {
                    source: "T_Icon_Rectangle.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    //anchors.margins: 2
                    //anchors.bottomMargin:10
                }
                onPressed: painter.setBtype(EButtonType.RECTANCGLE)
            }
            ToolButton {
                Image {
                    source: "T_Icon_Ellipse.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    //anchors.margins: 2
                    //anchors.bottomMargin:10
                }
                onPressed: painter.setBtype(EButtonType.ELLIPSE)
            }
            ToolButton {
                Image {
                    source: "T_Icon_Erase.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    //anchors.margins: 2
                    //anchors.bottomMargin:10
                }
                onPressed: painter.setBtype(EButtonType.ERASE)
            }
        }
    }

    Painter {
    id: painter
    x: 0
    y: 60
    width: 640
    height: 420
    }

    MouseArea {
        id: mouseArea
        x: 0
        y: 60
        width: 640
        height: 420
        property int px: 0
        property int py: 0

        onPressed:
        {
            if (mouse.button === Qt.LeftButton)
            {
                isMousePressed.value = true;
                px = mouseX;
                py = mouseY;
                painter.mousePressEvent(mouseX,mouseY)
            }
        }
        onReleased:
        {
            if (mouse.button === Qt.LeftButton)
            {
                isMousePressed.value = false;
                px = mouseX;
                py = mouseY;
                painter.mouseReleaseEvent(mouseX, mouseY)
            }
        }
        onPositionChanged:
        {
            if(isMousePressed)
            {
                px = mouseX;
                py = mouseY;
                x_text = mouseX;
                y_text = mouseY;
                painter.mouseMoveEvent(mouseX, mouseY)
            }
        }


        Text {
            id: element
            x: 300
            y: -60
            width: 100
            height: 40
            text: "x = " + x_text
            font.pixelSize: 12
        }
        Text {
            id: element1
            x: 400
            y: -60
            width: 100
            height: 40
            text: "y = " + y_text
            font.pixelSize: 12
        }

        Image {
            id: image
            anchors.fill: parent
            source: qmlFileName
            fillMode: Image.PreserveAspectFit
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:50;anchors_x:0;anchors_y:0}D{i:2;anchors_y:0}D{i:4;anchors_y:0}
D{i:6;anchors_y:0}D{i:8;anchors_y:0}D{i:10;anchors_y:0}
}
##^##*/

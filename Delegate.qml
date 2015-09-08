import QtQuick 2.3

Rectangle {
    property string name: "?"
    property string age: "?"

    signal clicked()

    width: parent.width
    height: 25

    property Gradient tmpGradient0: Gradient{}
    property Gradient tmpGradient: Gradient {
        GradientStop {color: "white"; position: 0}
        GradientStop {color: "lightgray"; position: 1}
    }
    gradient: tmpGradient
    color: "lightgray"


    Text {
        anchors.left: parent.left;
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        id: nameId
        text: parent.name
        color: "blue"
    }
    Text {
        id: nameAge
        text: "(" + parent.age + ")"
        anchors.left: nameId.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20
        color: "black"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed: {
            gradient = tmpGradient0
        }
        onReleased: {
            gradient = tmpGradient
        }
    }
}

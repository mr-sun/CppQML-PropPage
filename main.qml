import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("My Cpp+QML property page sample")

    function listProperty(it)
    {
        for (var p in it) {
            console.log(p + ":" + it[p])
        }
    }

    Component {
        id: del
        Delegate {
            name: model.name
            age: model.age
            onClicked: {
                propFrame.isUpdating = true
                propFrame.name = model.name
                propFrame.age = model.age
                propFrame.note = model.note
                propFrame.addr = model.addr
                propFrame.phone = model.phone
                propFrame.index = model.index
                propFrame.isUpdating = false
                //listProperty(modcpp)
            }
        }
    }
    ListView {
        id: lv
        x:10; y:10;
        width: 150
        height: 400
        model: modcpp
        delegate: del
    }

    PropertyFrame {
        property int index: -1
        property bool isUpdating: false
        id: propFrame
        anchors.left: lv.right
        anchors.right: parent.right
        anchors.margins: 10
        height: lv.height
        y: 10
        onChanged: {
            if (!isUpdating) {
                modcpp.setItemData2(index, value, role);
            }
        }
    }

}

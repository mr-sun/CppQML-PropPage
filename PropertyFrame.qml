import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: page

    property string name: "?"
    property int age: 0
    property string note: "?"
    property string addr: "?"
    property string phone: "?"

    signal changed(string value, string role)

    Grid {
        anchors.fill: parent
        anchors.margins: 20
        columns: 2
        spacing: 5

        Text {id: lblNameId; text: "Name: "}
        TextField {
            placeholderText: qsTr("Type the name here")
            text: name
            onTextChanged: {
                name = text
                page.changed(text, "name")
            }
        }

        Text {id: lblAgeId; text: "Age: "}
        TextField {
            placeholderText: qsTr("Type the age here")
            text: age
            onTextChanged: {
                age = text
                page.changed(text, "age")
            }
        }

        Text {id: lblAddrId; text: "Address: "}
        TextField {
            placeholderText: qsTr("Type the address here")
            text: addr
            onTextChanged: {
                addr = text
                page.changed(text, "addr")
            }
        }

        Text {id: lblPhoneId; text: "Phone: "}
        TextField {
            placeholderText: qsTr("Type the phone here")
            text: phone
            onTextChanged: {
                phone = text
                page.changed(text, "phone")
            }
        }

        Text {id: lblNoteId; text: "Note: "}
        TextArea {
            text: note
            height: 100
            onTextChanged: {
                note = text
                page.changed(text, "note")
            }
        }

    }
}

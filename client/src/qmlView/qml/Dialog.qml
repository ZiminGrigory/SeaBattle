import QtQuick 2.0

Rectangle {
	id: main
	width: parent.width
	height: parent.height
	color: "transparent"
	z: 10

	property alias text: message.text
	property alias backButtonVisible: backButton.visible
	property alias breakDialogOkVisible: breakDialogOk.visible
	property alias okButtonVisible: okButton.visible


	signal gameBreakDialogOkPressed();
	signal quitDialogOkPressed();
	signal quitDialogCancelPressed();

	Image{
		width: parent.width
		height: parent.height
		source: "qrc:/qml/qml/quitDilog.png"
	}

	Text{
		id: message
		width: parent.width * 0.8
		height: parent.height / 5
		anchors.top: parent.top
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.topMargin: parent.height / 5
		style: Text.Outline; styleColor: "black"
		text: "Вы уверены, что хотите выйти в главное меню?"
		font.family: "Helvetica"
		font.pointSize: height / 4
		wrapMode: Text.WordWrap
		color: "white"
	}

	Image{
		id: okButton
		width: parent.width / 3
		height: width
		anchors.bottom: main.bottom
		anchors.left: parent.left
		anchors.bottomMargin: main.width / 8
		anchors.leftMargin: width / 3
		source: "qrc:/qml/qml/yes.png"
		MouseArea{
			id:buttonOkMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				buttonOkMouseArea.clicked.connect(main.quitDialogOkPressed)
			}
			onClicked: {
				main.visible = false
			}
		}
	}

	Image{
		id: breakDialogOk
		width: parent.width / 3
		height: width
		anchors.bottom: main.bottom
		anchors.left: parent.left
		anchors.bottomMargin: main.width / 8
		anchors.leftMargin: width
		source: "qrc:/qml/qml/yes.png"
		MouseArea{
			id:breakDialogOkMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				breakDialogOkMouseArea.clicked.connect(main.gameBreakDialogOkPressed)
			}
			onClicked: {
				main.visible = false
			}
		}
	}

	Image{
		id: backButton
		width: parent.width / 3
		height: width
		anchors.bottom: main.bottom
		anchors.bottomMargin: main.width / 8
		anchors.right: parent.right
		anchors.rightMargin: width / 3
		source: "qrc:/qml/qml/no.png"
		MouseArea{
			id:buttonBackMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				buttonBackMouseArea.clicked.connect(main.quitDialogCancelPressed)
			}
			onClicked: {
				main.visible = false
			}
		}
	}
}

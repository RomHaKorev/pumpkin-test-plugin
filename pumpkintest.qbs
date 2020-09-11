import qbs

QtcPlugin {
	name: "PumpkinTest"

	Depends { name: "Core" }
	Depends { name: "CppTools" }
	Depends { name: "CPlusPlus" }
	Depends { name: "ProjectExplorer" }
	Depends { name: "QmlJS" }
	Depends { name: "QmlJSTools" }
	Depends { name: "Utils" }
	Depends { name: "Debugger" }
	Depends { name: "TextEditor" }

	pluginTestDepends: [
		"QbsProjectManager",
		"QmakeProjectManager"
	]

	Depends {
		name: "QtSupport"
		condition: qtc.testsEnabled
	}

	Depends {
		name: "Qt.testlib"
		condition: qtc.testsEnabled
	}

	Depends { name: "Qt.widgets" }

	files: [
	]
}

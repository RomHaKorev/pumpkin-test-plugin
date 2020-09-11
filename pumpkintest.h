#ifndef PUMPKINPLUGINPLUGIN_H
#define PUMPKINPLUGINPLUGIN_H

#include "pumpkinplugin_global.h"

#include <projectexplorer/project.h>
#include <extensionsystem/iplugin.h>

#include "testspane.h"

namespace PumpkinTest {
namespace Internal {

class PumpkinTestPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "PumpkinTest.json")

public:
	PumpkinTestPlugin();
	~PumpkinTestPlugin() override;

	bool initialize(const QStringList &arguments, QString *errorString) override;
	void extensionsInitialized() override;
	ShutdownFlag aboutToShutdown() override;

private slots:
	void scanProject(ProjectExplorer::Project*);

private:
	void triggerAction();

	TestsPane* pane;

};

} // namespace Internal
} // namespace Pumpkinplugin

#endif // PUMPKINPLUGINPLUGIN_H

#include "pumpkintest.h"
#include "pumpkinpluginconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <extensionsystem/pluginmanager.h>
#include <extensionsystem/pluginspec.h>

#include <projectexplorer/session.h>
#include <coreplugin/progressmanager/progressmanager.h>
#include <cpptools/cpptoolsconstants.h>
#include <cpptools/cppmodelmanager.h>
#include <utils/algorithm.h>

#include <cpptools/cppmodelmanager.h>
#include <cpptools/cppworkingcopy.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace PumpkinTest {
namespace Internal {

PumpkinTestPlugin::PumpkinTestPlugin()
{
	// Create your members
}

PumpkinTestPlugin::~PumpkinTestPlugin()
{
	// Unregister objects from the plugin manager's object pool
	// Delete members
}

bool PumpkinTestPlugin::initialize(const QStringList &arguments, QString *errorString)
{
	// Register objects in the plugin manager's object pool
	// Load settings
	// Add actions to menus
	// Connect to other plugins' signals
	// In the initialize function, a plugin can be sure that the plugins it
	// depends on have initialized their members.

	Q_UNUSED(arguments)
	Q_UNUSED(errorString)

	pane = new TestsPane();
	pane->popup(Core::IOutputPane::NoModeSwitch);

	ProjectExplorer::Project* project = ProjectExplorer::SessionManager::startupProject();

	connect(ProjectExplorer::SessionManager::instance(), &ProjectExplorer::SessionManager::startupProjectChanged, this, &PumpkinTestPlugin::scanProject);

	connect(progressManager, &Core::ProgressManager::allTasksFinished,
			this, &TestCodeParser::onAllTasksFinished);


	/*auto action = new QAction(tr("Pumpkinplugin Action"), this);
	Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
															 Core::Context(Core::Constants::C_GLOBAL));
	//cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
	connect(action, &QAction::triggered, this, &PumpkinpluginPlugin::triggerAction);

	Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
	menu->menu()->setTitle(tr("Pumpkin Tests"));
	menu->addAction(cmd);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

	//Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->menu()->actions()
	for (auto action: Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->menu()->actions())
	{
		if (action->text() == "&Tests")
		{
			for (auto testAction: action->menu()->actions())
			{
				qDebug() << testAction->metaObject()->;
			}
		}
	}*/

	/*for (auto plugin: ExtensionSystem::PluginManager::plugins())
	{
		if (plugin->name() == "AutoTest")
		{
			plugin->plugin()->dumpObjectTree();
		}
	}*/

	return true;
}

void PumpkinTestPlugin::extensionsInitialized()
{
	// Retrieve objects from the plugin manager's object pool
	// In the extensionsInitialized function, a plugin can be sure that all
	// plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag PumpkinTestPlugin::aboutToShutdown()
{
	// Save settings
	// Disconnect from signals that are not needed during shutdown
	// Hide UI (if you add UI that is not in the main window directly)
	return SynchronousShutdown;
}

void PumpkinTestPlugin::triggerAction()
{
	QMessageBox::information(Core::ICore::mainWindow(),
							 tr("Action Triggered"),
							 tr("This is an action from Pumpkinplugin."));
}


void PumpkinTestPlugin::scanProject(ProjectExplorer::Project* project)
{
	connect(project, &ProjectExplorer::Project::fileListChanged, this, [this, project]() {
		auto list = project->files(ProjectExplorer::Project::SourceFiles);
		for (auto filename: list)
		{
			project->projectFileIsDirty(filename);
			auto erd = CppTools::CppModelManager::instance()->snapshot();
		}
		QTimer::singleShot(10000, this, [list] {
			auto erd = CppTools::CppModelManager::instance()->snapshot();
			for (auto filename: list)
				qDebug() << filename << erd.document(filename);
		});
	});
}



} // namespace Internal
} // namespace Pumpkinplugin

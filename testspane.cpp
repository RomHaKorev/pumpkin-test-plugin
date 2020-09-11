#include "testspane.h"

#include <QPushButton>

TestsPane::TestsPane(QObject* parent): Core::IOutputPane(parent)
{
	content = new QPushButton("This is a Pumpkin Pane!");
	connect(content, &QPushButton::clicked, this, &TestsPane::run);
}

QWidget* TestsPane::outputWidget(QWidget* parent)
{
	content->setParent(parent);
	return content;
}

QString TestsPane::displayName() const
{
	return "Pumpkin Tests";
}

int TestsPane::priorityInStatusBar() const
{
	return 1;
}

void TestsPane::clearContents()
{

}

void TestsPane::visibilityChanged(bool visible)
{
	content->setVisible(visible);
}

void TestsPane::setFocus()
{
	content->setFocus();
}

bool TestsPane::hasFocus() const
{
	return content->hasFocus();
}

bool TestsPane::canFocus() const
{
	return true;
}

bool TestsPane::canNavigate() const
{
	return false;
}

bool TestsPane::canNext() const
{
	return false;
}

bool TestsPane::canPrevious() const
{
	return false;
}

void TestsPane::goToNext()
{

}

void TestsPane::goToPrev()
{

}


void TestsPane::run()
{

}

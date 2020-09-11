#ifndef TESTSPANE_H
#define TESTSPANE_H

#include <coreplugin/ioutputpane.h>

class QPushButton;

class TestsPane : public Core::IOutputPane
{
	Q_OBJECT
public:
	explicit TestsPane(QObject* parent=nullptr);

	// IOutputPane interface
public:
	QWidget* outputWidget(QWidget* parent);
	QString displayName() const;
	int priorityInStatusBar() const;
	void clearContents();
	void visibilityChanged(bool visible);
	void setFocus();
	bool hasFocus() const;
	bool canFocus() const;
	bool canNavigate() const;
	bool canNext() const;
	bool canPrevious() const;
	void goToNext();
	void goToPrev();

	QPushButton* content;
public slots:
		void run();
};

#endif // TESTSPANE_H

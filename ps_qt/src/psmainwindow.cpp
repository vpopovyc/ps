#include "psmainwindow.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>

PSMainWindow::PSMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumSize(PSApp::WIDTH, PSApp::HEIGHT);
    setMaximumSize(PSApp::WIDTH, PSApp::HEIGHT);
    setWindowTitle(tr("Particle System of your Daddy"));

    QMenu *edit = new QMenu(this);
    QAction *action = new QAction(tr("&Normal"), this);
    action->setShortcut(tr("CTRL+N"));
    action->setToolTip(tr("Normal"));
    action->setStatusTip(tr("Toggles Normal"));
    action->setCheckable(true);
    edit->addAction(action);
    menuBar()->addMenu(edit)->setText(tr("&Edit"));
}

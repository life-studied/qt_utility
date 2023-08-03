#include "progressdisplayer.h"
#include <QMessageBox>
qt_utility::ProgressDisplayer::ProgressDisplayer(int logNum)
{
    if(logNum!=ProDefault)
        num = logNum;
    oneLogPercent = 1.0/num;
    pWidget = new ProgressBarWidget;
}

qt_utility::ProgressDisplayer::~ProgressDisplayer()
{
    if(pWidget) delete pWidget;
}

void qt_utility::ProgressDisplayer::start()
{
    pWidget->clearTxt();
    pWidget->clearProBar();
    pWidget->showInProgressWidget();
}

void qt_utility::ProgressDisplayer::addLog(QString logStr)
{
    pWidget->addTxt(logStr);
    proPercent+=oneLogPercent;
    pWidget->addProBar(proPercent);
}

void qt_utility::ProgressDisplayer::fail(QString failStr)
{
    QMessageBox::warning(nullptr, "警告", failStr);
    pWidget->hideWidget();
}

void qt_utility::ProgressDisplayer::end(QString success)
{
    addLog(success);
    int finish = 100;
    pWidget->addProBar(finish);
    pWidget->showFinishWidget();
}

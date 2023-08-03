#ifndef PROGRESSDISPLAYER_H
#define PROGRESSDISPLAYER_H
#include <QString>
#include "progressbarwidget.h"
#include "logNum.h"
namespace qt_utility {

class ProgressDisplayer
{
public:
    ProgressDisplayer(int logNum = ProDefault);
    ~ProgressDisplayer();
    static const qsizetype ProDefault = -1;
public:
    void start();
    void addLog(QString logStr);
    void fail(QString failStr);
    void end(QString success);
    void reset();
private:
    ProgressBarWidget* pWidget;
    double proPercent = 0;
    double oneLogPercent;
    //执行脚本统计
    int num = LOGNUMBER;
};


}



#endif // PROGRESSDISPLAYER_H

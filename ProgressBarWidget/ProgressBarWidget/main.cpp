#include "progressdisplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto displayer = new qt_utility::ProgressDisplayer(100);
    displayer->start();
    for(int i = 0;i<100;i++)
    {
        displayer->addLog(QString("finish %1").arg(i));
    }
    displayer->end(QString("安装完成！"));
    return a.exec();
}

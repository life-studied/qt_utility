# ProgressBarWidget

​	A simple progress bar window tool that can be used in the following scenarios: installation, loading, updating, etc. It provides a display of logs and a progress bar.

## example

```cpp
#include "progressdisplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //create ProgressDisplayer, the total num of logs is needed
    auto displayer = new qt_utility::ProgressDisplayer(100);
    
    //make window shown
    displayer->start();
    
    //print logs
    for(int i = 0;i<100;i++)
    {
        displayer->addLog(QString("finish %1").arg(i));
    }
    
    //success log, make it finished to 100% directly
    displayer->end(QString("安装完成！"));
    
    //fail log, make it stopped and given a warning messageBox
    //displayer->fail(QString("something was wrong"));
    
    return a.exec();
}

```


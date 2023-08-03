#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProgressBarWidget; }
QT_END_NAMESPACE

class ProgressBarWidget : public QWidget
{
    Q_OBJECT

public:
    ProgressBarWidget(QWidget *parent = nullptr);
    ~ProgressBarWidget();
    void clearTxt();
    void clearProBar();
    void addTxt(QString txt);
    void addProBar(double percent);
    void hideWidget();
    void showInProgressWidget();
    void showFinishWidget();
private slots:
    void on_btnStop_clicked();

    void on_btnFinish_clicked();
signals:
    void userterminate();
    void userfinish();
private:
    Ui::ProgressBarWidget *ui;
};
#endif // PROGRESSBARWIDGET_H

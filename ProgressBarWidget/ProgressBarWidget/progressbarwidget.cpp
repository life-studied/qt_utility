#include "progressbarwidget.h"
#include "ui_progressbarwidget.h"

ProgressBarWidget::ProgressBarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProgressBarWidget)
{
    ui->setupUi(this);
}

ProgressBarWidget::~ProgressBarWidget()
{
    delete ui;
}

void ProgressBarWidget::clearTxt()
{
    ui->txtLog->clear();
}

void ProgressBarWidget::clearProBar()
{
    ui->proBar->setEnabled(true);
    ui->proBar->reset();
}

void ProgressBarWidget::addTxt(QString txt)
{
    ui->txtLog->append(txt);
}

void ProgressBarWidget::addProBar(double percent)
{
    ui->proBar->setValue((int)(percent*100));
}

void ProgressBarWidget::hideWidget()
{
    auto objList = findChildren<QWidget*>();
    for(int i = 0;i<objList.size();i++)
    {
        QWidget* widget = objList.at(i);
        widget->hide();
    }
    this->hide();
}

void ProgressBarWidget::showInProgressWidget()
{
    auto objList = findChildren<QWidget*>();
    for(int i = 0;i<objList.size();i++)
    {
        QWidget* widget = objList.at(i);
        if(widget==ui->btnFinish)
        {
            widget->hide();
            continue;
        }
        widget->show();
    }
    this->show();
}

void ProgressBarWidget::showFinishWidget()
{
    auto objList = findChildren<QWidget*>();
    for(int i = 0;i<objList.size();i++)
    {
        QWidget* widget = objList.at(i);
        if(widget==ui->btnStop)
        {
            widget->hide();
            continue;
        }
        widget->show();
    }
    this->show();
}


void ProgressBarWidget::on_btnStop_clicked()
{
    addTxt(QString("操作终止！"));
    ui->proBar->setDisabled(true);
    emit userterminate();
    showFinishWidget();
}


void ProgressBarWidget::on_btnFinish_clicked()
{
    emit userfinish();
    hideWidget();
}


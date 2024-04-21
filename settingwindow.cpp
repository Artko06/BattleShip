#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SettingWindow)
    , fieldFirstPlayer(new FieldFirstPlayer)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(fieldFirstPlayer, &FieldFirstPlayer::backSignalFirstWindow, this, &SettingWindow::backButton_from_firstField);
    connect(this, &SettingWindow::personButtonClick, fieldFirstPlayer, &FieldFirstPlayer::personButtonChoise);
    connect(this, &SettingWindow::botButtonClick, fieldFirstPlayer, &FieldFirstPlayer::botButtonChoise);
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::backButton_from_firstField()
{
    fieldFirstPlayer->close();
    this->showFullScreen();
}

void SettingWindow::on_botButton_clicked()
{
    this->close();
    fieldFirstPlayer->showFullScreen();
    emit botButtonClick();
}


void SettingWindow::on_personButton_clicked()
{
    this->close();
    fieldFirstPlayer->showFullScreen();
    emit personButtonClick();
}


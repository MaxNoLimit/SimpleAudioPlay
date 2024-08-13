#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    audioPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    audioPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(20);
    ui->position_bar_label->setText("0");
    ui->horizontalSlider->setMinimum(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_3_clicked()
{
    audioPlayer->pause();
    ui->position_bar_label->setText(QString::number(audioPlayer->position()));
    ui->horizontalSlider->setSliderPosition(audioPlayer->position());
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->position_bar_label->setText(QString::number(ui->horizontalSlider->sliderPosition()));
    audioPlayer->setPosition(ui->horizontalSlider->sliderPosition());
    audioPlayer->play();
}


void MainWindow::on_select_audio_file_button_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Select Audio FIle"), "", tr("MP3 Files (*.MP3)"));
    audioPlayer->setSource(QUrl(fileName));

    QFileInfo File(fileName);
    ui->file_name_label->setText(File.fileName());


    ui->position_bar_label->setText("0");
    ui->duration_label_audio_1->setText(QString::number(audioPlayer->duration()));
    ui->duration_bar_label->setText(QString::number(audioPlayer->duration()));
    ui->horizontalSlider->setMaximum(audioPlayer->duration());
    // audioPlayer->play();
    qDebug() << "Audio selected!";
}


void MainWindow::on_pushButton_clicked()
{
    ui->position_bar_label->setText("0");
    ui->duration_label_audio_1->setText(QString::number(audioPlayer->duration()));
    ui->duration_bar_label->setText(QString::number(audioPlayer->duration()));
    ui->horizontalSlider->setMaximum(audioPlayer->duration());

}


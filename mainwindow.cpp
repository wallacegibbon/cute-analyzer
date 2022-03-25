#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::handle_btn1_click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_btn1_click()
{
    // QMessageBox::about(this, "test signal", "this is just a test");
    qDebug() << "button 1 got clicked.";
    QString msg("hello");
    QFile file(QDir::home().absoluteFilePath("hello_qt.txt"));
    if (!file.open(QIODevice::WriteOnly))
    {
        qWarning() << "can not open file with write access";
        return;
    }
    QTextStream s(&file);
    s << msg;
}

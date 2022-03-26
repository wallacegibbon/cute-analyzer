#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>

void show_all_ports()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports)
    {
        qDebug() << "\t-- " << info.portName();
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handle_btn1_click);
    show_all_ports();
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
    QFile file(QDir::temp().absoluteFilePath("hello_qt.txt"));
    if (!file.open(QIODevice::Append))
    {
        qWarning() << "can not open file with write access";
        return;
    }
    QTextStream s(&file);
    s << msg;
}

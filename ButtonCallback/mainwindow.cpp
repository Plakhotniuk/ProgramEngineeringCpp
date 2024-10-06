#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Application started successfully!";

#ifdef QT_DEBUG
    qDebug() << "This is a debug build.";
#else
    qDebug() << "This is a release build.";
#endif

    connect(ui->button_get, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    connect(ui->button_reset, &QPushButton::clicked, this, &MainWindow::onResetClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{

    QString user_name = ui->lineEdit->text();

    // Check if the input field is empty and log a warning
    if (user_name.isEmpty()) {
        qWarning() << "Input field is empty. No greeting will be generated.";
        return;
    } else {
        qDebug() << "Input name:" << user_name;
    }

    QString greeting = "Hello, " + user_name + "!!!";

    // Log the generated greeting
    qDebug() << "Generated greeting:" << greeting;

    ui->label_greeting->setText(greeting);

    ui->button_get->setEnabled(false);
}

void MainWindow::onResetClicked()
{
    // Log the reset button click event
    qDebug() << "Reset button clicked";

    // Clear the input and output fields
    ui->label_greeting->clear();
    ui->lineEdit->clear();

    // Enable the Greet button
    ui->button_get->setEnabled(true);

    // Log the reset action
    qDebug() << "Input and output fields reset successfully.";
}


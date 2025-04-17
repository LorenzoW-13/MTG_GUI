#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <filesystem>

namespace fs = std::filesystem;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect ok button to close the application
    connect(ui->pushButton, &QPushButton::clicked, this, QApplication::quit);
}

MainWindow::~MainWindow()
{
    fs::remove_all("Test/Qt/build");
    delete ui;
    
}
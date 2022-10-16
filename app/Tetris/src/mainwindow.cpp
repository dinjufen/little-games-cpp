#include "inc/mainwindow.h"
#include<QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Tetris");
    disWidget = new DisplayWidget(this);
    scoreWidget = new ScoreWidget(this);
    centralWidget = new QWidget(this);
    QHBoxLayout h_layout;
    h_layout.addWidget(disWidget);
    h_layout.addWidget(scoreWidget);
    centralWidget->setLayout(&h_layout);
    centralWidget->setFixedSize(QSize(600, 800));
    setCentralWidget(centralWidget);

};

MainWindow::~MainWindow()
{
};

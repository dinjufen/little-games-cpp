//
// Created by 丁俊峰 on 2022/10/20.
//

#include "mainwindow.h"
#include<QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    setWindowTitle("Tetris");
    disWidget = new DisplayWidget(this);
    scoreWidget = new ScoreWidget(this);
    centralWidget = new QWidget(this);
    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(disWidget);
    h_layout->addWidget(scoreWidget);
    centralWidget->setLayout(h_layout);
    setCentralWidget(centralWidget);
    connect(disWidget, &DisplayWidget::signalScore, scoreWidget, &ScoreWidget::change_score);
    connect(disWidget, &DisplayWidget::signalShape, scoreWidget, &ScoreWidget::drawShape);
};

MainWindow::~MainWindow()
{
};
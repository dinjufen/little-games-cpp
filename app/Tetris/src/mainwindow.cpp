//
// Created by 丁俊峰 on 2022/10/20.
//

#include "mainwindow.h"
#include<QHBoxLayout>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    setWindowTitle("Tetris");
    disWidget = new DisplayWidget(this);
    scoreWidget = new ScoreWidget(this);
    centralWidget = new QWidget(this);
    controller = new ShapeController();
    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(disWidget);
    h_layout->addWidget(scoreWidget);
    centralWidget->setLayout(h_layout);
    setCentralWidget(centralWidget);

    connect(controller, &ShapeController::sigUpdateMat, disWidget, &DisplayWidget::slotUpdateMat);
    connect(controller, &ShapeController::sigUpdateShape, disWidget, &DisplayWidget::slotUpdateShape);
    connect(controller, &ShapeController::sigUpdateScore, scoreWidget, &ScoreWidget::slot_changeScore);
    connect(controller, &ShapeController::sigUpdateNext, scoreWidget, &ScoreWidget::sigUpdateNext);
    connect(scoreWidget, &ScoreWidget::sigLevelChanged, controller, &ShapeController::slotLevelChanged);

    QTimer::singleShot(0, controller, &ShapeController::slotStart);
}

MainWindow::~MainWindow()
{
    delete controller;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    const auto key = event->key();
    if (key == Qt::Key_Down) {
        controller->move_down();
    } else if (key == Qt::Key_Left) {
        controller->move_left();
    } else if (key == Qt::Key_Right) {
        controller->move_right();
    } else if (key == Qt::Key_Up) {
        controller->turn();
    } else if (key == Qt::Key_Space) {
        controller->pauseOrStart();
    }
    QMainWindow::keyPressEvent(event);
}
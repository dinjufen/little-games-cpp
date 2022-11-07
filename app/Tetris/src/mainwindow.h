#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DisplayWidget.h"
#include "ScoreWidget.h"
#include "Shape.h"
#include "ShapeController.h"

#define ROW 20
#define COL 10

class MainWindow : public QMainWindow
{
Q_OBJECT
private:
    DisplayWidget* disWidget = nullptr;
    ScoreWidget* scoreWidget = nullptr;
    QWidget* centralWidget = nullptr;
    ShapeController* controller = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
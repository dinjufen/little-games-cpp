#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inc/DisplayWidget.h"
#include "inc/scorewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
  private:
    DisplayWidget* disWidget = nullptr;
    ScoreWidget* scoreWidget = nullptr;
    QWidget* centralWidget = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

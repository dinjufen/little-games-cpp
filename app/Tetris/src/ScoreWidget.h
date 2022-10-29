#ifndef SCORE_WIDGET_H
#define SCORE_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include "Button.h"
#include "NextShape.h"
#include "ShapeFactory.h"

class ScoreWidget : public QWidget
{
Q_OBJECT
private:
    int score = 0;

    QLabel* lb_score = nullptr;
    QLabel* show_score = nullptr;
    QLabel* lb_level = nullptr;
    QLabel* show_level = nullptr;
    Button* btn_restart = nullptr;
    Button* btn_exit = nullptr;
public slots:
    void change_score();
    void drawShape();
public:
    ScoreWidget(QWidget *parent = nullptr);
    ~ScoreWidget();

    NextShape* shape_widget = nullptr;

    void restart();
};

#endif // SCOREWIDGET_H
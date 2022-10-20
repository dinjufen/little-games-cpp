#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

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
    QWidget* shape_widget = nullptr;
    QLabel* lb_scre = nullptr;
    QLabel* show_score = nullptr;
    QLabel* lb_level = nullptr;
    QLabel* show_level = nullptr;

public:
    ScoreWidget(QWidget *parent = nullptr);
    ~ScoreWidget();

    void restart();
    void change_score();
};

#endif // SCOREWIDGET_H
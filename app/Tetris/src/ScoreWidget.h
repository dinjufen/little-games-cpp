#ifndef SCORE_WIDGET_H
#define SCORE_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include "Button.h"
#include "NextShape.h"
#include "ShapeFactory.h"

class ScoreWidget : public QWidget
{
Q_OBJECT
private:
    QLabel* lb_score = nullptr;
    QLabel* show_score = nullptr;
    QLabel* lb_level = nullptr;
    Button* btn_restart = nullptr;
    Button* btn_exit = nullptr;
    QButtonGroup* level_btn_group;
public slots:
    void slot_changeScore(int score);

signals:
    void sigUpdateNext(const vector<Coor>& coor_list, const QColor& color);
    void sigLevelChanged(const int level);

public:
    ScoreWidget(QWidget *parent = nullptr);
    ~ScoreWidget();

    NextShape* shape_widget = nullptr;

    void restart();
};

#endif // SCOREWIDGET_H
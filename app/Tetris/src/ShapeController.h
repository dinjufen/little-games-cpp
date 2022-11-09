//
// Created by 丁俊峰 on 2022/10/29.
//

#ifndef LITTLE_GAMES_CPP_SHAPECONTROLLER_H
#define LITTLE_GAMES_CPP_SHAPECONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QTimerEvent>
#include <QKeyEvent>
#include <vector>
#include <QColor>
#include "Shape.h"
#include <bitset>

#define ROW 20
#define COL 10

using namespace std;

class ShapeController : public QObject {
Q_OBJECT
private:
    Shape* cur_shape;
    Shape* next_shape;
    int timer_id;
    int interval;
    int total_score;
    bool running;
    vector<vector<int>> matrix;
    vector<bitset<COL>> mat;

private:
    bool down_blocked() const;
    bool left_blocked() const;
    bool right_blocked() const;
    bool up_blocked() const;
    bool turn_blocked() const;

public:
    ShapeController();
    ~ShapeController();

    void move_down();
    void move_left();
    void move_right();
    void turn();

public slots:
    void slotStart();
    void slotStop();
    void slotLevelChanged(int level);
    void pauseOrStart();

    signals:
    void sigUpdateMat(const vector<bitset<COL>>& mat);
    void sigUpdateShape(const vector<Coor>& coor_list, const QColor& color);
    void sigUpdateNext(const vector<Coor>& coor_list, const QColor& color);
    void sigUpdateScore(int score);
    void sigGameOver();

protected:
    virtual void timerEvent(QTimerEvent* event) override;
};


#endif //LITTLE_GAMES_CPP_SHAPECONTROLLER_H

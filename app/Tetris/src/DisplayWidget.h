#ifndef __DISPLAY_WIDGET_H__
#define __DISPLAY_WIDGET_H__
#include<QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include "Shape.h"

#define ROW 20
#define COL 10

class DisplayWidget : public QWidget
{
    Q_OBJECT
private:
    int interval;
    QPixmap* pix = nullptr;
    int matrix[ROW][COL];
    int timer_id;
    int count = 0;

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void timerEvent(QTimerEvent* event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;

public:
    signals:
        void signalScore(); // 得分
        void signalShape(); // 请求下一个方块

public:
    DisplayWidget(QWidget* parent = nullptr);
    ~DisplayWidget();
    void start();
    void updateMat();
    void destroyRow(const int row);
    bool checkOnes(const int row);
    void drawShape();
    void clearOldShape(bool turn = false);
    void drawMat();
    bool down_blocked();
    bool right_blocked();
    bool left_blocked();
    bool turn_blocked();
};

#endif // DISPLAYWIDGET_H
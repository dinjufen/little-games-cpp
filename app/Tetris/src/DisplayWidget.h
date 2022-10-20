#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include<QWidget>
#include <QPixmap>
#include "Shape.h"

#define ROW 20
#define COL 10

class DisplayWidget : public QWidget
{
    Q_OBJECT
private:
    int interval;
    Shape* cur_shape = nullptr;
    QPixmap* pix = nullptr;
    int matrix[ROW][COL] = {0};

public:
    DisplayWidget(QWidget* parent = nullptr);
    ~DisplayWidget();
};

#endif // DISPLAYWIDGET_H
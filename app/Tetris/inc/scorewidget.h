#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include "shape_factory.h"

class ScoreWidget : public QWidget
{
    Q_OBJECT
private:

public:
    ScoreWidget(QWidget *parent = nullptr);
    ~ScoreWidget();
};

#endif // SCOREWIDGET_H

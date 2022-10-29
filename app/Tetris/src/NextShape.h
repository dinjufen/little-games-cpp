#ifndef __NEXT_SHAPE__
#define __NEXT_SHAPE__
#include <QWidget>
#include <QPixmap>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include "ShapeFactory.h"

class NextShape : public QWidget {
private:
    QPixmap* pix = nullptr;
public:
    NextShape(QWidget* parent);

    void slot_drawShape();

protected:
    virtual void paintEvent(QPaintEvent* event);
};

#endif
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
    vector<Coor> old_coor_list;

public:
    NextShape(QWidget* parent);
    ~NextShape();

public slots:
    void slot_drawShape(const vector<Coor>& coor_list, const QColor& color);

protected:
    virtual void paintEvent(QPaintEvent* event);
};

#endif
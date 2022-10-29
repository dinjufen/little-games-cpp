#include "NextShape.h"
#include "ShapeFactory.h"
#include <Qt>

NextShape::NextShape(QWidget* parent) {
    setFixedSize(250, 250);
    pix = new QPixmap(size());
    pix->fill(Qt::white);
}

void NextShape::slot_drawShape() {
    Shape* next_shape = ShapeFactory::GetInstance()->get_next();
    vector<Coor> coor = next_shape->get_vir_coor();
    QPen pen;
    pen.setColor(next_shape->color);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(next_shape->color);
    QPainter painter;
    painter.begin(pix);
    painter.setBrush(brush);
    painter.setPen(pen);
    for (const auto& c : coor) {
        painter.drawRect(50 + c.x * 45, 50 + c.y * 45, 42, 42);
    }
    painter.end();
    update();
}

void NextShape::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, *pix);
}
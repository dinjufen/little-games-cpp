#include "NextShape.h"
#include "ShapeFactory.h"
#include <Qt>

NextShape::NextShape(QWidget* parent) {
    setFixedSize(250, 250);
    pix = new QPixmap(size());
    pix->fill(Qt::white);
}

void NextShape::slot_drawShape(const vector<Coor>& coor_list, const QColor& color) {
    QPainter painter;
    painter.begin(pix);
    pix->fill(Qt::white);
    painter.setBrush(color);
    painter.setPen(color);
    for (const auto& c : coor_list) {
        painter.drawRect(50 + c.x * 45, 50 + c.y * 45, 42, 42);
    }
    painter.end();
    update();
}

void NextShape::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, *pix);
}

NextShape::~NextShape() {
    delete pix;
}
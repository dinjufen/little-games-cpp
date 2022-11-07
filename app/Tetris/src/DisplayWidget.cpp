#include<QWidget>
#include <Qt>
#include <QPainter>
#include <QDebug>
#include "DisplayWidget.h"
#include "ShapeFactory.h"


DisplayWidget::DisplayWidget(QWidget* parent)
    : QWidget(parent)
{
    setFixedSize(460, 900);
    pix = new QPixmap(this->size());
    pix->fill(Qt::white);
}


DisplayWidget::~DisplayWidget() {
    delete pix;
}

void DisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, *pix);
    QWidget::paintEvent(event);
}

void DisplayWidget::slotUpdateMat(const vector<bitset<COL>>& mat) {
    old_coor_list.clear();
    pix->fill(Qt::white);
    QPainter painter;
    painter.begin(pix);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    for (int y = 0;y < mat.size();y++) {
        for (int x = 0;x < mat[y].size();x++) {
            if (mat[y][x]) {
                painter.drawRect(x * 45, y * 45, 42, 42);
            }
        }
    }
    painter.end();
    update();
}

void DisplayWidget::slotUpdateShape(const vector<Coor> &coor_list, const QColor &color) {
    QPainter painter;
    QPen pen;
    QBrush brush(Qt::SolidPattern);
    painter.begin(pix);

    if (!old_coor_list.empty()) {
        pen.setColor(Qt::white);
        brush.setColor(Qt::white);
        painter.setBrush(brush);
        painter.setPen(pen);
        for (const Coor &coor: old_coor_list) {
            painter.drawRect(coor.x * 45, coor.y * 45, 42, 42);
        }
    }
    pen.setColor(color);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.setPen(pen);
    for (const Coor& coor : coor_list) {
        painter.drawRect(coor.x * 45, coor.y * 45, 42, 42);
    }
    painter.end();
    update();
    old_coor_list = coor_list;
}

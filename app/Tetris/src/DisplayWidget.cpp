#include<QWidget>
#include <Qt>
#include <QPainter>
#include <QDebug>
#include "DisplayWidget.h"
#include "ShapeFactory.h"


DisplayWidget::DisplayWidget(QWidget* parent)
    : QWidget(parent)
    , interval(1000)
{
    setFixedSize(460, 900);
    pix = new QPixmap(this->size());
    memset(matrix, 0, sizeof matrix);
    start();
}


DisplayWidget::~DisplayWidget() {

}

void DisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, *pix);
    QWidget::paintEvent(event);
}

void DisplayWidget::timerEvent(QTimerEvent *event) {
    count++;
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    if (down_blocked()) {
        qDebug() << "timer out down_blocked";
//        killTimer(timer_id);
        emit signalShape();
        const auto& offset = cur_shape->get_offset();
        for (const auto& coor : cur_shape->get_vir_coor()) {
            matrix[coor.y + offset.y][coor.x + offset.x] = 1;
        }
        clearOldShape();
        updateMat();
    } else {
        qDebug() << "timer out " << count;
        cur_shape->move_down();
        clearOldShape();
        drawShape();
    }
    update();
}

void DisplayWidget::keyPressEvent(QKeyEvent *event) {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    const auto k = event->key();
    if (k == Qt::Key_Up) {
        if (turn_blocked()) return;
        cur_shape->turn();
        clearOldShape(true);
        drawShape();
    }
    else if (k == Qt::Key_Left) {
        if (left_blocked()) return;
        cur_shape->move_left();
        clearOldShape();
        drawShape();
    }
    else if (k == Qt::Key_Right) {
        if (right_blocked()) return;
        cur_shape->move_right();
        clearOldShape();
        drawShape();
    }
    else if (k == Qt::Key_Down) {
        if (!cur_shape) {
            if (down_blocked()) {

            }
        }
    }
}

void DisplayWidget::start() {
    pix->fill(Qt::white);
    timer_id = startTimer(interval);
}

void DisplayWidget::updateMat() {
    for (int y = 0;y < ROW;y++) {
        if (checkOnes(y)) {
            destroyRow(y);
        }
    }
    drawMat();
}

// 销毁某行
void DisplayWidget::destroyRow(const int row) {
    emit signalScore();
    for (int i = row;i >= 0;i--) {
        for (int j = 0;j < COL;j++) {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (int j = 0;j < COL;j++) {
        matrix[0][j] = 0;
    }
}

// 检查某一行是否全部占满
bool DisplayWidget::checkOnes(const int row) {
    for (int j = 0;j < COL;j++) {
        if (matrix[row][j] == 0) return false;
    }
    return true;
}

void DisplayWidget::drawMat() {
    pix->fill(Qt::white);
    QPainter painter;
    QBrush brush(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter.setBrush(brush);
    for (int x = 0;x < COL;x++) {
        for (int y = 0;y < ROW;y++) {
            if (matrix[y][x]) {
                painter.drawRect(x * 45, y * 45, 42, 42);
            }
        }
    }
    painter.end();
    update();
}

void DisplayWidget::drawShape() {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    QPainter painter;
    QPen pen;
    pen.setColor(cur_shape->color);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(cur_shape->color);
    painter.begin(pix);
    painter.setBrush(brush);
    painter.setPen(pen);
    Coor offset = cur_shape->get_offset();
    const auto& vir_coor = cur_shape->get_vir_coor();
    for (const Coor& coor : vir_coor) {
        painter.drawRect((coor.x + offset.x) * 45, (coor.y + offset.y)*45, 42, 42);
    }
    painter.end();
}

void DisplayWidget::clearOldShape(bool turn) {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(Qt::white);
    painter.begin(pix);
    painter.setBrush(brush);
    painter.setPen(pen);
    Coor offset = cur_shape->get_old_offset();
    const auto& vir_coor = turn ? cur_shape->get_old_shape() : cur_shape->get_vir_coor();
    for (const Coor& coor : vir_coor) {
        painter.drawRect((coor.x + offset.x) * 45, (coor.y + offset.y) * 45, 42, 42);
    }
    painter.end();
}

bool DisplayWidget::left_blocked() {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_vir_coor()) {
        // 如果已经靠左墙了
        if ((coor.x + offset.x) == 0) return true;
        // 如果左移一格会碰到方块
        if ((coor.y + offset.y) < ROW && (coor.x + offset.x - 1) >= 0 && matrix[coor.y + offset.y][coor.x + offset.x - 1]) return true;
    }
    return false;
}

bool DisplayWidget::right_blocked() {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_vir_coor()) {
        // 如果已经靠右墙了
        if ((coor.x + offset.x) == (COL - 1)) return true;
        // 如果右移一格会碰到方块
        if ((coor.y + offset.y) < ROW && (coor.x + offset.x + 1) < COL && matrix[coor.y + offset.y][coor.x + offset.x + 1]) return true;
    }
    return false;
}

bool DisplayWidget::down_blocked() {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    ShapeFactory::GetInstance()->generate_shape();
    const Coor& offset = cur_shape->get_offset();
    const auto& vir_coor = cur_shape->get_vir_coor();
    for (const auto& coor : vir_coor) {
        // 如果已经在最下了
        qInfo() << "coor y = " << coor.y << " x = " << coor.x << " offset y = " << offset.y << " x = " << offset.x;
        if ((coor.y + offset.y) == (ROW - 1)) {
            qInfo() << "down blocked 1";
            return true;
        }
        // 如果下移一格会碰到方块也认为到底了
        if (matrix[coor.y + offset.y + 1][coor.x + offset.x]) {
            qInfo() << "down blocked 2";
            return true;
            // 不能继续下移的情况下，如果此时不完全在画布内，则认为游戏结束
//            for (const auto& coor : cur_shape->get_vir_coor()) {
//                if ()
//            }
        }
    }
    return false;
}

bool DisplayWidget::turn_blocked() {
    Shape* cur_shape = ShapeFactory::GetInstance()->get_shape();
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_turn_shape()) {
        if (coor.y + offset.y == ROW - 1) return true;
        if (coor.x + offset.x == COL - 1) return true;
        if (coor.x + offset.x == 0) return true;
        if (matrix[coor.y + offset.y + 1][coor.x + offset.x]) return true;
        if (matrix[coor.y + offset.y][coor.x + offset.x + 1]) return true;
        if (matrix[coor.y + offset.y][coor.x + offset.x - 1]) return true;
    }
    return false;
}
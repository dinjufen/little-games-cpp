//
// Created by 丁俊峰 on 2022/10/29.
//

#include "ShapeController.h"
#include "ShapeFactory.h"
#include <QDebug>

ShapeController::ShapeController()
    : cur_shape(nullptr)
    , next_shape(nullptr)
    , interval(1000)
    , timer_id(0)
    , total_score(0)
    , matrix(ROW, vector<int>(COL, 0))
    , mat(ROW, 0)
    , running(false) {

}

ShapeController::~ShapeController() noexcept {}

void ShapeController::slotStart() {
    cur_shape = ShapeFactory::get_shape();
    next_shape = ShapeFactory::get_shape();
    timer_id = startTimer(interval);
    running = true;
    emit sigUpdateNext(next_shape->get_coor(), next_shape->color);
}

void ShapeController::slotStop() {
    running = false;
    killTimer(timer_id);
    timer_id = 0;
}

void ShapeController::slotLevelChanged(int level) {
    switch (level) {
        case 0:
            interval = 1000;
            break;
        case 1:
            interval = 800;
            break;
        case 2:
            interval = 500;
            break;
    }
    if (running) {
        killTimer(timer_id);
        timer_id = startTimer(interval);
    }
}

void ShapeController::pauseOrStart() {
    running = !running;
}

void ShapeController::timerEvent(QTimerEvent *event) {
    if (running) {
        move_down();
    }
}

void ShapeController::move_down() {
    if (!running) return;
    if (up_blocked()) {
        emit sigGameOver();
    }
    if (down_blocked()) {
        const auto coor_list = cur_shape->get_coor();
        const Coor& offset = cur_shape->get_offset();
        for (const Coor& coor : coor_list) {
            mat[coor.y + offset.y][coor.x + offset.x] = 1;
        }
        vector<int> left_rows;
        int _score = 0;
        for (int i = 0;i < mat.size();i++) {
            if (mat[i].all()) {
                _score++;
            } else {
                left_rows.push_back(i);
            }
        }
        int j = ROW - 1;
        for (int i = left_rows.size() - 1;i >= 0;i--) {
            mat[j] = mat[left_rows[i]];
            j--;
        }
        for (;j >= 0;j--) {
            mat[j].reset();
        }
        Shape* del_shape = cur_shape;
        cur_shape = next_shape;
        next_shape = ShapeFactory::get_shape();
        delete del_shape;
        total_score += _score;
        emit sigUpdateMat(mat);
        emit sigUpdateNext(next_shape->get_coor(), next_shape->color);
        emit sigUpdateScore(total_score);
    } else {
        cur_shape->move_down();
        vector<Coor> coor_list(cur_shape->get_coor());
        const Coor& offset = cur_shape->get_offset();
        for (Coor& coor : coor_list) {
            coor.x += offset.x;
            coor.y += offset.y;
        }
        emit sigUpdateShape(coor_list, cur_shape->color); // 通知更新显示方块
    }
}

void ShapeController::move_right() {
    if (!running) return;
    if (!cur_shape) return;
    if (right_blocked()) return;
    cur_shape->move_right();
    vector<Coor> coor_list(cur_shape->get_coor());
    const Coor& offset = cur_shape->get_offset();
    for (Coor& coor : coor_list) {
        coor.x += offset.x;
        coor.y += offset.y;
    }
    emit sigUpdateShape(coor_list, cur_shape->color); // 通知更新显示方块
}

void ShapeController::move_left() {
    if (!running) return;
    if (!cur_shape) return;
    if (left_blocked()) return;
    cur_shape->move_left();
    vector<Coor> coor_list(cur_shape->get_coor());
    const Coor& offset = cur_shape->get_offset();
    for (Coor& coor : coor_list) {
        coor.x += offset.x;
        coor.y += offset.y;
    }
    emit sigUpdateShape(coor_list, cur_shape->color); // 通知更新显示方块
}

void ShapeController::turn() {
    if (!running) return;
    if (!cur_shape) return;
    if (turn_blocked()) return;
    cur_shape->turn();
    vector<Coor> coor_list(cur_shape->get_coor());
    const Coor& offset = cur_shape->get_offset();
    for (Coor& coor : coor_list) {
        coor.x += offset.x;
        coor.y += offset.y;
    }
    emit sigUpdateShape(coor_list, cur_shape->color); // 通知更新显示方块
}

bool ShapeController::down_blocked() const {
    const Coor& offset = cur_shape->get_offset();
    const auto& vir_coor = cur_shape->get_coor();
    for (const auto& coor : vir_coor) {
        // 如果已经在最下了
        qInfo() << "coor y = " << coor.y << " x = " << coor.x << " offset y = " << offset.y << " x = " << offset.x;
        if (coor.y + offset.y + 1 == ROW) {
            qInfo() << "down blocked 1";
            return true;
        }
        // 如果下移一格会碰到方块也认为到底了
        if (mat[coor.y + offset.y + 1][coor.x + offset.x]) {
            qInfo() << "down blocked 2";
            return true;
        }
    }
    return false;
}

bool ShapeController::up_blocked() const {
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_coor()) {
        if (mat[coor.y + offset.y][coor.x + offset.x]) {
            return true;
        }
    }
    return false;
}

bool ShapeController::left_blocked() const {
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_coor()) {
        // 如果已经靠左墙了
        if ((coor.x + offset.x) == 0) return true;
        // 如果左移一格会碰到方块
        if ((coor.y + offset.y) < ROW && (coor.x + offset.x - 1) >= 0 && mat[coor.y + offset.y][coor.x + offset.x - 1]) return true;
    }
    return false;
}

bool ShapeController::right_blocked() const {
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_coor()) {
        // 如果已经靠右墙了
        if (coor.x + offset.x + 1 == COL) return true;
        // 如果右移一格会碰到方块
        if ((coor.y + offset.y) < ROW && (coor.x + offset.x + 1) < COL && mat[coor.y + offset.y][coor.x + offset.x + 1]) return true;
    }
    return false;
}

bool ShapeController::turn_blocked() const {
    const auto& offset = cur_shape->get_offset();
    for (const auto& coor : cur_shape->get_turn_shape()) {
        if (coor.y + offset.y + 1 >= ROW) return true;
        if (coor.x + offset.x + 1 >= COL) return true;
        if (coor.x + offset.x == 0) return true;
        if (mat[coor.y + offset.y + 1][coor.x + offset.x]) return true;
        if (mat[coor.y + offset.y][coor.x + offset.x + 1]) return true;
        if (mat[coor.y + offset.y][coor.x + offset.x - 1]) return true;
    }
    return false;
}
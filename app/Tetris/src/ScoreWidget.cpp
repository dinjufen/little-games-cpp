//
// Created by 丁俊峰 on 2022/10/20.
//

#include <QFormLayout>
#include "ScoreWidget.h"
#include "NextShape.h"
#include<QSize>


ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(400);
    shape_widget = new NextShape(this);
    lb_score = new QLabel(tr("Score"), this);
    show_score = new QLabel(tr("0"), this);
    lb_level = new QLabel(tr("Level"), this);
    show_level = new QLabel(tr("1"), this);
    btn_restart = new Button(tr("Restart"), this);
    btn_exit = new Button(tr("Exit"), this);
    QFormLayout* score_layout = new QFormLayout();
    score_layout->addRow(lb_level, show_level);
    score_layout->addRow(lb_score, show_score);
    connect(btn_restart, &Button::clicked, this, &ScoreWidget::restart);
    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(shape_widget);
    v_layout->addLayout(score_layout);
    v_layout->addWidget(btn_restart);
    v_layout->addWidget(btn_exit);
    v_layout->addStretch();
    setLayout(v_layout);
    shape_widget->slot_drawShape();
}

ScoreWidget::~ScoreWidget() {}



void ScoreWidget::restart() {
    score = 0;
    show_score->setText("0");
}

void ScoreWidget::change_score() {
    score++;
    show_score->setText(QString(score));
}

void ScoreWidget::drawShape() {
    shape_widget->slot_drawShape();
}
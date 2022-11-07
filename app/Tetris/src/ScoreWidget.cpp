//
// Created by 丁俊峰 on 2022/10/20.
//

#include <QFormLayout>
#include "ScoreWidget.h"
#include "NextShape.h"
#include<QSize>


ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(270);
    shape_widget = new NextShape(this);
    lb_score = new QLabel(tr("Score"), this);
    show_score = new QLabel(tr("0"), this);
    lb_level = new QLabel(tr("Level"), this);
    QHBoxLayout* layout_btn_box = new QHBoxLayout();
    QRadioButton* btn_easy = new QRadioButton(tr("Easy"), this);
    QRadioButton* btn_medium = new QRadioButton(tr("Medium"), this);
    QRadioButton* btn_hard = new QRadioButton(tr("Hard"), this);
    btn_easy->setChecked(true);
    level_btn_group = new QButtonGroup(this);
    level_btn_group->addButton(btn_easy, 0);
    level_btn_group->addButton(btn_medium, 1);
    level_btn_group->addButton(btn_hard, 2);
    level_btn_group->setExclusive(true);
    layout_btn_box->addWidget(btn_easy);
    layout_btn_box->addWidget(btn_medium);
    layout_btn_box->addWidget(btn_hard);
    btn_restart = new Button(tr("Restart"), this);
    btn_exit = new Button(tr("Exit"), this);
    QFormLayout* score_layout = new QFormLayout();
    score_layout->addRow(lb_level, layout_btn_box);
    score_layout->addRow(lb_score, show_score);
    connect(btn_restart, &Button::clicked, this, &ScoreWidget::restart);
    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(shape_widget);
    v_layout->addLayout(score_layout);
    v_layout->addWidget(btn_restart);
    v_layout->addWidget(btn_exit);
    v_layout->addStretch();
    setLayout(v_layout);

    connect(this, &ScoreWidget::sigUpdateNext, shape_widget, &NextShape::slot_drawShape);
    connect(level_btn_group, &QButtonGroup::idClicked, this, &ScoreWidget::sigLevelChanged);
}

ScoreWidget::~ScoreWidget() {}



void ScoreWidget::restart() {
    show_score->setText("0");
}

void ScoreWidget::slot_changeScore(int score) {
    show_score->setText(QString::number(score));
}
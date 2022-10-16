#include<QWidget>
#include<QSize>
#include "inc/DisplayWidget.h"

DisplayWidget::DisplayWidget(QWidget* parent) : QWidget(parent)
{
    QSize size(400, 800);
    setFixedSize(size);
}


DisplayWidget::~DisplayWidget() {

}

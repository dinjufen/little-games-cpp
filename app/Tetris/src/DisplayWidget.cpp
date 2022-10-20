#include<QWidget>
#include<QSize>
#include <Qt>
#include "DisplayWidget.h"


DisplayWidget::DisplayWidget(QWidget* parent)
    : QWidget(parent)
    , interval(1000)
{
    QSize size(460, 900);
    setFixedSize(size);
    pix = new QPixmap(this->size());
    pix->fill(Qt::white);

}


DisplayWidget::~DisplayWidget() {

}
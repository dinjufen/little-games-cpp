#pragma once
#include <QWidget>
#include <QPixmap>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include "shape_factory.h"

class NextShape : public QWidget {
private:
	QPixmap* pix = nullptr;
public:
	NextShape(QWidget* parent);

	void drawShape();

	virtual void paintEvent(QPaintEvent* event);
};
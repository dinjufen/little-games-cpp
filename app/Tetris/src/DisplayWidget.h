#ifndef __DISPLAY_WIDGET_H__
#define __DISPLAY_WIDGET_H__
#include<QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include "Shape.h"
#include "ShapeController.h"

class DisplayWidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap* pix = nullptr;
    vector<Coor> old_coor_list;

protected:
    virtual void paintEvent(QPaintEvent* event) override;

public:
    DisplayWidget(QWidget* parent = nullptr);
    ~DisplayWidget();

public slots:
    void slotUpdateMat(const vector<bitset<COL>>& mat);
    void slotUpdateShape(const vector<Coor>& coor_list, const QColor& color);
};

#endif // DISPLAYWIDGET_H
#include "inc/button.h"
#include<QFont>
#include<Qt>

Button::Button(const QString& name, QWidget* parent) : QPushButton(parent)
{
    setFixedSize(100, 40);
    setText(name);
#if(WIN32)
    setFont(QFont("Microsoft YaHei", 12));
#else
    setFont(QFont("PingFang SC", 12));
#endif
    setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

Button::~Button() {}

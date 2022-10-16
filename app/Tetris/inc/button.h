#ifndef BUTTON_H
#define BUTTON_H

#include<QPushButton>
#include<QWidget>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(const QString& name, QWidget* parent = nullptr);
    ~Button();
};

#endif // BUTTON_H

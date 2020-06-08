#ifndef INPUTKEYBOARD_WINDOW_H
#define INPUTKEYBOARD_WINDOW_H
#include "new_realization.h"
#include <QMainWindow>

namespace Ui {
class InputKeyboard_Window;
}
class InputKeyboard_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputKeyboard_Window(QWidget *parent = nullptr);
    ~InputKeyboard_Window();


private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::InputKeyboard_Window *ui;
};




#endif // INPUTKEYBOARD_WINDOW_H

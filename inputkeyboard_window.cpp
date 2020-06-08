#include "inputkeyboard_window.h"
#include "ui_inputkeyboard_window.h"
#include "mainwindow.h"
#include "mainwindow_second.h"
#include "new_realization.h"

CListOfStudents newInputtedList;
int isOpen = 0;
extern CListOfStudents *Group;
InputKeyboard_Window::InputKeyboard_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InputKeyboard_Window)
{
    ui->setupUi(this);
    ui->lineEdit_Surname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,255}"), this ));
     ui->lineEdit_Name->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,255}"), this ));
    ui->spinBox_Mark1->setMinimum(2);
    ui->spinBox_Mark1->setMaximum(5);
    ui->spinBox_Mark2->setMinimum(2);
    ui->spinBox_Mark2->setMaximum(5);
    ui->spinBox_Mark3->setMinimum(2);
    ui->spinBox_Mark3->setMaximum(5);
    ui->spinBox_Mark4->setMinimum(2);
    ui->spinBox_Mark4->setMaximum(5);
    ui->spinBox_Mark5->setMinimum(2);
    ui->spinBox_Mark5->setMaximum(5);
    QDate w(2003, 12, 21);
    ui->dateEdit->setMaximumDate(w);
}
MainWindow_Second *newWindow;
MainWindow *s;
int iCancel = 1;

InputKeyboard_Window::~InputKeyboard_Window()
{
    delete ui;
}

void InputKeyboard_Window::on_pushButton_Cancel_clicked()
{
    iCancel = 2;
    if(isOpen == 0)
    {
        s = new MainWindow();
        s->show();
        s->setWindowTitle("List Of Students");
        QIcon icon("://rec//img//icons8_checklist_64.png");
        s->setWindowIcon(icon);
        this->close();
    }else{
        newWindow = new MainWindow_Second();
        newWindow->show();
        newWindow->setWindowTitle("List Of Students");
        QIcon icon("://rec//img//icons8_checklist_64.png");
        newWindow->setWindowIcon(icon);
          this->close();
    }

}

string gName;
string gSurname;
int gData[3];
int gMarks[5];
void InputKeyboard_Window::on_pushButton_OK_clicked()
{
    iCancel = 1;
    isOpen++;
    QDate date = ui->dateEdit->date();
    gSurname = ui->lineEdit_Surname->text().toStdString();
    gName=ui->lineEdit_Name->text().toStdString();
    gData[0] = date.day();
    gData[1] = date.month();
    gData[2] = date.year();
    gMarks[0] = ui->spinBox_Mark1->text().toInt();
    gMarks[1] = ui->spinBox_Mark2->text().toInt();
    gMarks[2] = ui->spinBox_Mark3->text().toInt();
    gMarks[3] = ui->spinBox_Mark4->text().toInt();
    gMarks[4] = ui->spinBox_Mark5->text().toInt();


        newWindow = new MainWindow_Second();
        newWindow->show();
        newWindow->setWindowTitle("List Of Students");
        QIcon icon("://rec//img//icons8_checklist_64.png");
        newWindow->setWindowIcon(icon);
          this->close();

}

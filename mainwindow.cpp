#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QMessageBox"
#include "mainwindow_second.h"
#include "inputkeyboard_window.h"

MainWindow_Second *windows;
InputKeyboard_Window *inputKey;
int gChoose;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}
extern int isOpen;

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_close_program_clicked()
{ 
    this->close();
}

void MainWindow::on_pushButton_Keyboard_Reading_clicked()
{

gChoose = 1;
inputKey = new InputKeyboard_Window();
inputKey->show();

inputKey->setWindowTitle("List Of Students");
QIcon icon("://rec//img//icons8_checklist_64.png");
inputKey->setWindowIcon(icon);

this->close();
}


 QString file ;
void MainWindow::on_pushButton_File_Reading_clicked()
{
     file = QFileDialog::getOpenFileName(this,"Open a file");
    if(!file.isEmpty()) {
        QFile File(file);
        if(!File.open(QFile::ReadOnly)){
            QMessageBox::information(0, "error", File.errorString());
            File.close();
        }
        else{

          gChoose = 2;
          windows = new MainWindow_Second();
          windows->show();
          windows->setWindowTitle("List Of Students");
          QIcon icon("://rec//img//icons8_checklist_64.png");
          windows->setWindowIcon(icon);
          isOpen++;
          this->close();
          File.close();
        }
    }
}

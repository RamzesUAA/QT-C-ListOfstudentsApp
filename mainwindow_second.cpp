#include "mainwindow_second.h"
#include "ui_mainwindow_second.h"
#include "new_realization.h"
#include "inputkeyboard_window.h"
using namespace std;

  CListOfStudents *Group = NULL;
 extern int gChoose;
 extern CListOfStudents newInputtedList;
 extern string gName;
 extern string gSurname;
 extern int gData[3];
 extern int gMarks[5];
 extern  QString file;
 extern int iCancel;

void AddingStudentsToList(CListOfStudents **ppNode);
void NamingTableWidgetsHeaders(QTableWidget *widget);
MainWindow_Second::MainWindow_Second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Second)
{
    ui->setupUi(this);

    if(gChoose==1)
    {
       NamingTableWidgetsHeaders(ui->tableWidget);
       if(iCancel == 1){
        Group->AddingStudentsToList(&Group,gName, gSurname, gData, gMarks);
        ui->statusbar->showMessage("Student(s) were added to list.");
       }

       Group->OutputtingToTableWidget(ui->tableWidget, Group);

    }

    if(gChoose == 2)
    {
        NamingTableWidgetsHeaders(ui->tableWidget);
        Group->ReadingFromFile(&Group, file);
        Group->OutputtingToTableWidget(ui->tableWidget, Group);
         ui->statusbar->showMessage("Student(s) were added to list.");
    }
    ui->pushButton_Sorting->setToolTip("Sort students by name in descending order");
    ui->pushButton_Removing->setToolTip("Remove all students with marks two");
    ui->pushButton_Outputting->setToolTip("Output 5 students with the worst average marks");
    ui->pushButton_ReadFromFile->setToolTip("Read data from file");
}

MainWindow_Second::~MainWindow_Second()
{
    delete ui;
}

void NamingTableWidgetsHeaders(QTableWidget *widget)
{
    widget->setColumnCount(7);
    widget->setRowCount(30);
    QStringList sNamesOfHeader;
    sNamesOfHeader << "Surname" << "Name" << "Day of birth" << "Month of birth" << "Year of birth" << "Marks" << "Average";
    widget->setHorizontalHeaderLabels(sNamesOfHeader);
    widget->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    widget->setColumnWidth(0, 150);
    widget->setColumnWidth(1, 150);
    widget->setColumnWidth(2, 118);
    widget->setColumnWidth(3, 150);
    widget->setColumnWidth(4, 150);
    widget->setColumnWidth(5, 120);
    widget->setColumnWidth(6, 100);
    widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void MainWindow_Second::on_pushButton_Sorting_clicked()
{
     Group->bubbleSort(&Group);
     Group->OutputtingToTableWidget(ui->tableWidget, Group);
     ui->statusbar->showMessage("The list of students was sorted.");
}

void MainWindow_Second::on_pushButton_Removing_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "List Of Students",
                                                             "Do you want to delete elements form the list.\n"
                                                             "This will prevent the list from returning to its previous appearance.",
                                                             QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(reply == QMessageBox::Yes){
            Group->RemoveStudentsWithMarksTwo(&Group);
            Group->OutputtingToTableWidget(ui->tableWidget, Group);
             ui->statusbar->showMessage("Students with marks two were removed.");
        }
}



void MainWindow_Second::on_pushButton_Exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "List Of Students",
                                                             "Do you want to close the program?\n"
                                                             "All unsaved data will be lost",
                                                             QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
       this->close();
    }

}

void MainWindow_Second::on_pushButton_Adding_clicked()
{
    gChoose = 1;
    InputKeyboard_Window *w = new InputKeyboard_Window();
    w->show();
    w->setWindowTitle("List Of Students");
    QIcon icon("C://Users//User//Desktop//icons8_checklist_64");
    w->setWindowIcon(icon);
    this->close();
}

void MainWindow_Second::on_pushButton_Outputting_clicked()
{
    Group->Output5StudetsWithWorstAvrgMarks(Group, ui->tableWidget);
}

void MainWindow_Second::on_pushButton_ClearingList_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this, "List Of Students",
                                                             "Do you want to clear current list.",
                                                             QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
    Group->ClearTheList(&Group);
    Group->OutputtingToTableWidget(ui->tableWidget, Group);
    ui->statusbar->showMessage("The list is cleared.");
    }
}

void MainWindow_Second::on_pushButton_Support_clicked()
{
     QMessageBox::information(this, "Support","You can ask us something, by writing to the email: ramzesball@gmail.com ", QMessageBox::Ok);
}

void MainWindow_Second::on_actionSave_2_triggered()
{
     QString filePath = "C:\\Users\\User\\Desktop\\Laba_VIPZ_ListOfStudents\\outputData.txt";

    if(!filePath.isEmpty()) {
            QFile File(filePath);
            if(!File.open(QFile::ReadOnly)){

               // MainWindow_Second::on_actionSave_as_2_triggered();
                QMessageBox::information(0, "error", File.errorString());
                File.close();
            }
            else{
                File.close();
                }
    }
    Group->PrintInFile(&Group, filePath);
    ui->statusbar->showMessage("Data was written to "+filePath);
}

void MainWindow_Second::on_actionSave_as_2_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open a file");
    if(!filePath.isEmpty()) {
            QFile File(filePath);
            if(!File.open(QFile::ReadOnly)){
                QMessageBox::information(0, "error", File.errorString());
                File.close();
            }
            else{
                File.close();
                }
    }
    Group->PrintInFile(&Group, filePath);
     ui->statusbar->showMessage("Data was written to "+filePath);
}

void MainWindow_Second::on_pushButton_SavingToFile_clicked()
{

}

void MainWindow_Second::on_actionInformation_triggered()
{
     QMessageBox::information(this, "About the pogram","The name of application: List of students.\n" "Creator: Roman Alberda.", QMessageBox::Ok);

}


void MainWindow_Second::on_actionOur_contacts_triggered()
{
   QMessageBox::information(this, "Support","You can ask us something, by writing to the email: ramzesball@gmail.com ", QMessageBox::Ok);
}

void MainWindow_Second::on_actionOpen_2_triggered()
{
    MainWindow_Second::on_pushButton_SavingToFile_clicked();
}

void MainWindow_Second::on_actionAdd_new_student_triggered()
{
    MainWindow_Second::on_pushButton_Adding_clicked();
}

void MainWindow_Second::on_actionBy_the_surname_in_decrease_order_triggered()
{
     MainWindow_Second::on_pushButton_Sorting_clicked();
}

void MainWindow_Second::on_action5_students_with_the_highest_average_marks_triggered()
{
     MainWindow_Second::on_pushButton_Outputting_clicked();
}

void MainWindow_Second::on_actionStudent_with_mark_s_two_triggered()
{
     MainWindow_Second::on_pushButton_Removing_clicked();
}

void MainWindow_Second::on_pushButton_ReadFromFile_clicked()
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
          Group = new CListOfStudents();
          Group = NULL;

          NamingTableWidgetsHeaders(ui->tableWidget);

          Group->ReadingFromFile(&Group, file);
          Group->OutputtingToTableWidget(ui->tableWidget, Group);
          File.close();
        }
     }
}

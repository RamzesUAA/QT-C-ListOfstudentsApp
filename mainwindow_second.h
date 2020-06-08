#ifndef MAINWINDOW_SECOND_H
#define MAINWINDOW_SECOND_H
#include <QMainWindow>

namespace Ui {
class MainWindow_Second;
}

class MainWindow_Second : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Second(QWidget *parent = nullptr);
    ~MainWindow_Second();

private slots:
    void on_pushButton_Sorting_clicked();

    void on_pushButton_Removing_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_Adding_clicked();

    void on_pushButton_Outputting_clicked();

    void on_pushButton_ClearingList_clicked();

    void on_pushButton_Support_clicked();

    void on_actionSave_2_triggered();

    void on_actionSave_as_2_triggered();

    void on_pushButton_SavingToFile_clicked();

    void on_actionInformation_triggered();

    void on_actionOur_contacts_triggered();

    void on_actionOpen_2_triggered();

    void on_actionAdd_new_student_triggered();

    void on_actionBy_the_surname_in_decrease_order_triggered();

    void on_action5_students_with_the_highest_average_marks_triggered();

    void on_actionStudent_with_mark_s_two_triggered();

    void on_pushButton_ReadFromFile_clicked();

private:
    Ui::MainWindow_Second *ui;
};


#endif // MAINWINDOW_SECOND_H

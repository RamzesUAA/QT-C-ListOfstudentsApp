#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("List Of Students");
    QIcon icon("://rec//img//icons8_checklist_64.png");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}

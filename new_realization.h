#ifndef NEW_REALIZATION_H
#define NEW_REALIZATION_H

#include "QTableWidget"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "QMessageBox"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QMenu"
#include "QMenuBar"
#include "QMainWindow"
#include <iostream>
#include <fstream>
#include <string.h>

#define SIZE_OF_NAME 25
#define COUNT_OF_MARKS 5

using namespace  std;
class CListOfStudents
{
public:
     string m_sSurname;
     string m_sName;
     int m_nDay;
     int m_nMonth;
     int m_nYear;
     int m_nMarks[COUNT_OF_MARKS];
     float m_fltAverage;
     class CListOfStudents *m_pNext;

public:
    //realization of reading from the file
    void ReadingFromFile(CListOfStudents **ppNode, QString path);

    //here I output data to the table widget in  the next order:
    //surname, name, day of birth, month of birth, year of birth, marks(5)
    void OutputtingToTableWidget(QTableWidget *widget, CListOfStudents *pNode);
    void bubbleSort( CListOfStudents **start);
    void AddingStudentsToList(CListOfStudents **ppNode, string pName, string pSurname, int pData[], int pMarks[]);
    CListOfStudents *PreviousStudent(CListOfStudents *pNode, CListOfStudents *pItem);
    void RemoveStudentsWithMarksTwo(CListOfStudents **ppGroup);
    void Output5StudetsWithWorstAvrgMarks(CListOfStudents *ppGroup, QTableWidget *widget);
    void ClearTheList(CListOfStudents **ppNode);
    void PrintInFile(CListOfStudents **m_pStart, QString filePath);
};

#endif // NEW_REALIZATION_H

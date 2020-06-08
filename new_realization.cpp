#include "new_realization.h"
#include "QMessageBox"


bool isEmptyList(CListOfStudents *pNode)
{
    return pNode == NULL;
}
//--------------------------------------------------------------------------------
void CListOfStudents::ClearTheList(CListOfStudents **ppNode)
{


    CListOfStudents* current = *ppNode;
    CListOfStudents* next;

    while (current != NULL)
    {
        next = current->m_pNext;
        free(current);
        current = next;
    }

    *ppNode = NULL;
}


//--------------------------------------------------------------------------------
void CListOfStudents::OutputtingToTableWidget(QTableWidget *widget, CListOfStudents *pNode)
{
  widget->clear();

    for(int i = 0 ; pNode != NULL; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            if(j == 0)
            {

               QString itm = QString::fromStdString(pNode->m_sSurname);
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 1)
            {
                QString itm = QString::fromStdString(pNode->m_sName);
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 2)
            {
                QString itm = QString::number(pNode->m_nDay);
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 3)
            {
                QString itm = QString::number(pNode->m_nMonth);
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 4)
            {
               QString itm = QString::number(pNode->m_nYear);
               QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 5)
            {
                QString itm;
                for(int i = 0 ; i < 5; ++i)
                {
                    itm += QString::number(pNode->m_nMarks[i]);
                    itm += " ";
                }
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }else if(j == 6)
            {
                QString itm = QString::number(pNode->m_fltAverage);
                QTableWidgetItem *istm = new QTableWidgetItem(itm);
                widget->setItem(i, j, istm);
            }
        }
         pNode = pNode->m_pNext;
    }
    QStringList sNamesOfHeader;
    sNamesOfHeader << "Surname" << "Name" << "Day of birth" << "Month of birth" << "Year of birth" << "Marks" << "Average";
    widget->setHorizontalHeaderLabels(sNamesOfHeader);
}
//--------------------------------------------------------------------------------

void CListOfStudents::ReadingFromFile(CListOfStudents **ppNode, QString path)
{
    string filePath = path.toStdString();
    ifstream file(filePath);
    string name;
    string surname;
    int day, month, year;
    int marks[5];
    double dCounterOfMarks;
    CListOfStudents::ClearTheList(ppNode);

 CListOfStudents *temp = NULL;
       if(file.is_open())
       {
           while (file >> surname >> name >> day >> month >> year >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4]) {  //перевіряє, чи був досягнутий кінець файлу

               CListOfStudents *pNewElement = new CListOfStudents;
               dCounterOfMarks = 0;
               pNewElement->m_sSurname = surname;
               for (int i = 0; i < (pNewElement->m_sSurname).length(); ++i) {
                   if (!isalpha(pNewElement->m_sSurname[i])) {
                     QMessageBox msg;
                     QIcon icon ("://rec//img//icons8_checklist_64.png");
                     msg.setWindowIcon(icon);
                     msg.setIcon(QMessageBox::Critical);
                     msg.setText("The file contains an incorrect surname");
                     msg.setDetailedText("The surname should be inputted like in this example: Shevchenko");
                     msg.setInformativeText("Close and try again.");
                     msg.setStandardButtons(QMessageBox::Close);
                     msg.exec();
                     return;
                   }
               }

               pNewElement->m_sName = name;
               for (int i = 0; i < (pNewElement->m_sName).length(); ++i) {
                   if (!isalpha(pNewElement->m_sName[i])) {
                     QMessageBox msg;
                     QIcon icon ("://rec//img//icons8_checklist_64.png");
                     msg.setWindowIcon(icon);
                     msg.setIcon(QMessageBox::Critical);
                     msg.setText("The file contains an incorrect name");
                     msg.setDetailedText("The surname should be inputted like in this example: Taras");
                     msg.setInformativeText("Close and try again.");
                     msg.setStandardButtons(QMessageBox::Close);
                     msg.exec();
                     return;
                   }
               }

               pNewElement->m_nDay = day;
                   if (pNewElement->m_nDay < 1 || pNewElement->m_nDay > 31){
                       QMessageBox msg;
                       QIcon icon ("://rec//img//icons8_checklist_64.png");
                       msg.setWindowIcon(icon);
                       msg.setIcon(QMessageBox::Critical);
                       msg.setText("The file contains an incorrect day of birth");
                       msg.setDetailedText("The day should be inputted like in this example: 22");
                       msg.setInformativeText("Close and try again.");
                       msg.setStandardButtons(QMessageBox::Close);
                       msg.exec();
                       return;
               }

               pNewElement->m_nMonth = month;
               if (pNewElement->m_nMonth < 1 || pNewElement->m_nMonth > 12){
                   QMessageBox msg;
                   QIcon icon ("://rec//img//icons8_checklist_64.png");
                   msg.setWindowIcon(icon);
                   msg.setIcon(QMessageBox::Critical);
                   msg.setText("The file contains an incorrect month of birth");
                   msg.setDetailedText("The month should be inputted like in this example: 12");
                   msg.setInformativeText("Close and try again.");
                   msg.setStandardButtons(QMessageBox::Close);
                   msg.exec();
                   return;
                }

               pNewElement->m_nYear = year;
               if (pNewElement->m_nYear < 1980 || pNewElement->m_nYear > 2003){
                   QMessageBox msg;
                   QIcon icon ("://rec//img//icons8_checklist_64.png");
                   msg.setWindowIcon(icon);
                   msg.setIcon(QMessageBox::Critical);
                   msg.setText("The file contains an incorrect year of birth");
                   msg.setDetailedText("The year should be inputted like in this example: 2001");
                   msg.setInformativeText("Close and try again.");
                   msg.setStandardButtons(QMessageBox::Close);
                   msg.exec();
                   return;
                }

               for(int i = 0 ; i < 5; ++i)
               {
               pNewElement->m_nMarks[i] = marks[i];
               dCounterOfMarks +=marks[i];

               if (pNewElement->m_nMarks[i] < 2 || pNewElement->m_nMarks[i] > 5){
                   QMessageBox msg;
                   QIcon icon ("://rec//img//icons8_checklist_64.png");
                   msg.setWindowIcon(icon);
                   msg.setIcon(QMessageBox::Critical);
                   msg.setText("The file contains an incorrect marks");
                   msg.setDetailedText("The marks should be inputted like in this example: 3 3 4 5 5");
                   msg.setInformativeText("Close and try again.");
                   msg.setStandardButtons(QMessageBox::Close);
                   msg.exec();
                   return;
                    }
               }
               pNewElement->m_fltAverage = dCounterOfMarks / COUNT_OF_MARKS;
               pNewElement->m_pNext = NULL;

               if (!*ppNode)
               {
                   *ppNode = pNewElement;
                   temp = pNewElement;
               }
               else
               {
                   temp->m_pNext = pNewElement;
                   temp = temp->m_pNext;
               }
           }
       }

        file.close();
}
//--------------------------------------------------------------------------------

void swap( CListOfStudents *a,  CListOfStudents *b);
void CListOfStudents::bubbleSort( CListOfStudents **start)
{
    int k = isEmptyList(*start);
    if(k == 1)
    {
        QMessageBox msg;
        QIcon icon ("://rec//img//icons8_checklist_64.png");
        msg.setWindowIcon(icon);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("List of students");
        msg.setText("The list is empty. Please, close and enter data.");
        msg.setStandardButtons(QMessageBox::Close);
        msg.exec();
        return;
    }

    int swapped, i;
     CListOfStudents *ptr1;
     CListOfStudents *lptr = NULL;

    /* Checking for empty list */
    if (*start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = *start;

        while (ptr1->m_pNext != lptr)
        {
            if (ptr1->m_sSurname.compare(ptr1->m_pNext->m_sSurname) < 0)
            {
                swap(ptr1, ptr1->m_pNext);
                swapped = 1;
            }
            ptr1 = ptr1->m_pNext;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(CListOfStudents  *a, CListOfStudents  *b)
{
    string name = a->m_sName;
    string surname = a->m_sSurname;
    int day = a->m_nDay;
    int month = a->m_nMonth;
    int year  = a->m_nYear;
    int marks[5];
    float avrg = a->m_fltAverage;
    for(int i = 0; i < 5; ++i)
    {
        marks[i] = a->m_nMarks[i];
    }

    a->m_sName = b->m_sName;
    a->m_sSurname = b->m_sSurname;
    a->m_nDay = b->m_nDay;
    a->m_nMonth = b->m_nMonth;
    a->m_nYear = b->m_nYear;
    a->m_fltAverage = b->m_fltAverage;
    for(int i = 0; i < 5; ++i)
    {
         a->m_nMarks[i] = b->m_nMarks[i];
    }

    b->m_sName = name;
    b->m_sSurname = surname;
    b->m_nDay = day;
    b->m_nMonth = month;
    b->m_nYear = year;
    b->m_fltAverage = avrg;
    for(int i = 0; i < 5; ++i)
    {
        b->m_nMarks[i] = marks[i];
    }
}
//--------------------------------------------------------------------------------

void CListOfStudents::AddingStudentsToList(CListOfStudents **ppNode, string pName, string pSurname, int pData[3], int pMarks[5])
{

        string name = pName;
        string surname = pSurname;
        int day = pData[0];
        int month = pData[1];
        int year  = pData[2];
        int marks[5];
        marks[0] = pMarks[0];
        marks[1] = pMarks[1];
        marks[2] = pMarks[2];
        marks[3] = pMarks[3];
        marks[4] = pMarks[4];

        double dCounterOfMarks;
        CListOfStudents *pNewElement = new CListOfStudents;
         dCounterOfMarks = 0;
         pNewElement->m_sSurname = surname;
         pNewElement->m_sName = name;
         pNewElement->m_nDay = day;
         pNewElement->m_nMonth = month;
             pNewElement->m_nYear = year;
         for(int i = 0 ; i < 5; ++i)
         {
         pNewElement->m_nMarks[i] = marks[i];
         dCounterOfMarks +=marks[i];
         }
         pNewElement->m_fltAverage = dCounterOfMarks / COUNT_OF_MARKS;
         pNewElement->m_pNext = NULL;
          CListOfStudents *pListEnd = NULL;
        pListEnd = *ppNode;
         if (!(pListEnd))
         {
            (*ppNode) = pNewElement;
         }else
         {
             while((pListEnd)->m_pNext != NULL)
             {
                pListEnd = pListEnd->m_pNext;
             }
                pListEnd->m_pNext = pNewElement;
         }
}
//--------------------------------------------------------------------------------

void CListOfStudents::RemoveStudentsWithMarksTwo(CListOfStudents **ppGroup)
{
    int k = isEmptyList(*ppGroup);
    if(k == 1)
    {
        QMessageBox msg;
        QIcon icon ("://rec//img//icons8_checklist_64.png");
        msg.setWindowIcon(icon);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("List of students");
        msg.setText("The list is empty. Please, close and enter data.");
        msg.setStandardButtons(QMessageBox::Close);
        msg.exec();
        return;
    }

        CListOfStudents *NewElementPrevious = NULL, *pNewElementCurrent = *ppGroup;

        while (pNewElementCurrent) {
            if (!NewElementPrevious && (pNewElementCurrent->m_nMarks[0] == 2 || pNewElementCurrent->m_nMarks[1] == 2 || pNewElementCurrent->m_nMarks[2] == 2 || pNewElementCurrent->m_nMarks[3] == 2 || pNewElementCurrent->m_nMarks[4] == 2)) {
                *ppGroup = pNewElementCurrent->m_pNext;
                free(pNewElementCurrent);
                pNewElementCurrent = *ppGroup;
                continue;
            }
            if (pNewElementCurrent->m_nMarks[0] == 2 || pNewElementCurrent->m_nMarks[0] == 2 || pNewElementCurrent->m_nMarks[1] == 2 || pNewElementCurrent->m_nMarks[2] == 2 || pNewElementCurrent->m_nMarks[3] == 2 || pNewElementCurrent->m_nMarks[4] == 2) {
                NewElementPrevious->m_pNext = pNewElementCurrent->m_pNext;
                free(pNewElementCurrent);
                pNewElementCurrent = NewElementPrevious->m_pNext;
                continue;
            }
            NewElementPrevious = pNewElementCurrent;
            pNewElementCurrent = NewElementPrevious->m_pNext;
        }
}
//--------------------------------------------------------------------------------

void CListOfStudents::Output5StudetsWithWorstAvrgMarks(CListOfStudents *ppGroup, QTableWidget *widget)
{

    int k = isEmptyList(ppGroup);
    if(k == 1)
    {
        QMessageBox msg;
        QIcon icon ("://rec//img//icons8_checklist_64.png");
        msg.setWindowIcon(icon);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("List of students");
        msg.setText("The list is empty. Please, close and enter data.");
        msg.setStandardButtons(QMessageBox::Close);
        msg.exec();
        return;
    }

    CListOfStudents* pTemp = ppGroup;
    int nNumOfStudents = 0;
    while (pTemp->m_pNext != NULL) {

        nNumOfStudents++;
        pTemp = pTemp->m_pNext;
    }
    if (nNumOfStudents < 5)
    {
        QMessageBox::information(0, "List of students","To use the outputting, the list should consist of a minimum of 5 students.", QMessageBox::Ok);
        return;
    }


    widget->clear();
    int swapped, i;
    CListOfStudents *pNode = ppGroup;
    CListOfStudents *ptr1;
    CListOfStudents *lptr = NULL;

    /* Checking for empty list */
    if (ppGroup == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = ppGroup;

        while (ptr1->m_pNext != lptr)
        {
            if (ptr1->m_fltAverage > ptr1->m_pNext->m_fltAverage)
            {
                swap(ptr1, ptr1->m_pNext);
                swapped = 1;
            }
            ptr1 = ptr1->m_pNext;
        }
        lptr = ptr1;
    }
    while (swapped);

for(int i = 0; i < 5; ++i)
 {

     for(int j = 0; j < 7; ++j)
     {
         if(j == 0)
         {

            QString itm = QString::fromStdString(pNode->m_sSurname);
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 1)
         {
             QString itm = QString::fromStdString(pNode->m_sName);
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 2)
         {
             QString itm = QString::number(pNode->m_nDay);
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 3)
         {
             QString itm = QString::number(pNode->m_nMonth);
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 4)
         {
            QString itm = QString::number(pNode->m_nYear);
            QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 5)
         {
             QString itm;
             for(int i = 0 ; i < 5; ++i)
             {
                 itm += QString::number(pNode->m_nMarks[i]);
                 itm += " ";
             }
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }else if(j == 6)
         {
             QString itm = QString::number(pNode->m_fltAverage);
             QTableWidgetItem *istm = new QTableWidgetItem(itm);
             widget->setItem(i, j, istm);
         }
     }
      pNode = pNode->m_pNext;
 }
}
//--------------------------------------------------------------------------------

void CListOfStudents::PrintInFile(CListOfStudents **m_pStart, QString filePath)
{
    int k = isEmptyList(*m_pStart);
    if(k == 1)
    {
        QMessageBox msg;
        QIcon icon ("://rec//img//icons8_checklist_64.png");
        msg.setWindowIcon(icon);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("List of students");
        msg.setText("The list is empty. Please, close and enter data.");
        msg.setStandardButtons(QMessageBox::Close);
        msg.exec();
        return;
    }

    std::string path = filePath.toStdString();
    std::ofstream file(path);

    CListOfStudents *pCurr = *m_pStart;
    while(pCurr != NULL)
    {
        file<<pCurr->m_sSurname<<" "<<pCurr->m_sName<<" "<<pCurr->m_nDay<<" "<<pCurr->m_nMonth<<" "<<pCurr->m_nYear;
        for(int i = 0; i<5; i++)
        {
            file<<" "<<pCurr->m_nMarks[i];
        }
        file<<" "<< pCurr->m_fltAverage;

        file<<"\n";
        pCurr = pCurr->m_pNext;
    }
}
//--------------------------------------------------------------------------------

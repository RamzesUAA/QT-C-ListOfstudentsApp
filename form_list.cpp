#include "form_list.h"
#include "ui_form_list.h"
#include "realisation.h"
#include "mainwindow.h"

void OutPuttingData(QTableWidget *widget, SlistOfStudents *pNode);
void ReadingFromFile(const char *pRootName, SlistOfStudents **ppNode);

const char *QString2char(QString str)
{
    QByteArray byteArray;
    const char *cstr;

    byteArray = str.toUtf8();
    cstr = byteArray.constData();

    return(cstr);
}

Form_List::Form_List(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_List)
{

    SStudent *MainList = nullptr;
    ui->setupUi(this);
 //  MainList->m_nDay = 2;




      //vbl->setMenuBar(mb);
      //setLayout(vbl);

      resize(400,400);


    if(gChoose == 2)
    {
    //ReadingFromFile("list.txt", &MainList);
    }


   OutPuttingData(ui->tableWidget, MainList);

   /*QString itm = QString::number(MainList->m_nDay);
    QTableWidgetItem *istm = new QTableWidgetItem(itm);
    ui->tableWidget->setItem(0, 0, istm);*/


  /*
    QString file = QFileDialog::getOpenFileName(this,"Open a file");

   if(!file.isEmpty())
   {
       QFile sFile(file);
       if(sFile.open(QFile::ReadOnly | QFile::Text))
       {


           QTextStream in(&sFile);
           QString text = in.readAll();



       }
      MainList->m_chSurname = QString2char("Kek");
       sFile.close();
   }
*/




}

Form_List::~Form_List()
{
    delete ui;
}


void OutPuttingData(QTableWidget *widget, SlistOfStudents *pNode)
{
    widget->setRowCount(1);
    widget->setColumnCount(5);

     QString itm = QString(pNode->m_chName);
    QTableWidgetItem *istm = new QTableWidgetItem(itm);
    widget->setItem(0, 0, istm);
}

void TestReading()
{

}

int EmpetyFile(const char* pRootName)
{
    FILE* fp;
    fp = fopen(pRootName, "r+");
    int size;
    if (NULL != fp) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        if (0 == size) {
            printf("file is empty\n");
            fclose(fp);
            return 0;
        }
    }
}
void ReadingFromFile(const char *pRootName, SlistOfStudents **ppNode)
{
    FILE *fp;
      if (!(fp = fopen(pRootName, "r+"))) {
          printf("You entered wrong file name");
          fclose(fp);
          return;
      }

      SlistOfStudents *pNewElement = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
      int nSymbol;
      int nNumOfStudents = 1;
      int size;

      if (!EmpetyFile(pRootName))
      {
          return;
      }

      do {
          int isTrue = 0;
          if (!(*ppNode))
          {

              (*ppNode) = pNewElement;
          }

          double dCounterOfMarks = 0;

          fscanf(fp, "%s", pNewElement->m_chSurname);
          for (int i = 0; i < strlen(pNewElement->m_chSurname); ++i) {
              if (!isalpha(pNewElement->m_chSurname[i])) {
                  printf("You read incorrect surname in %d student", nNumOfStudents);
                  return;
              }
          }
          fscanf(fp, "%s", pNewElement->m_chName);
          for (int i = 0; i < strlen(pNewElement->m_chName); ++i) {
              if (!isalpha(pNewElement->m_chName[i])) {
                  printf("You read incorrect name in %d student", nNumOfStudents);
                  return;
              }
          }

          fscanf(fp, "%d", &pNewElement->m_nDay);
          for (int i = 1; i <= 31; ++i) {
              if (pNewElement->m_nDay == i)
                  isTrue++;
          }
          if (isTrue != 1) {
              printf("You read incorrect day of birth in %d student", nNumOfStudents);
              return;
          }

          fscanf(fp, "%d", &pNewElement->m_nMonth);
          for (int i = 1; i <= 12; ++i) {
              if (pNewElement->m_nMonth == i)
                  isTrue++;
          }
          if (isTrue != 2) {
              printf("You read incorrect month of birth in %d student", nNumOfStudents);
              return;
          }

          fscanf(fp, "%d", &pNewElement->m_nYear);
          for (int i = 1970; i <= 2020; ++i) {
              if (pNewElement->m_nYear == i)
                  isTrue++;
          }
          if (isTrue != 3) {
              printf("You read incorrect year of birth in %d student", nNumOfStudents);
              return;
          }

          for (int i = 0; i < COUNT_OF_MARKS; ++i) {
              fscanf(fp, "%d", &pNewElement->m_nMarks[i]);
              dCounterOfMarks += pNewElement->m_nMarks[i];
          }

          int isMarksTrue = 0;
          for (int i = 0; i < COUNT_OF_MARKS; ++i) {
              for (int j = 2; j <= 5; ++j) {
                  if ((pNewElement->m_nMarks[i]) == j) {
                      isMarksTrue++;
                  }
              }
          }

          if (isMarksTrue != 5) {
              printf("You read incorrect mark in %d student", nNumOfStudents);
              return;
          }

          pNewElement->m_fltAverage = dCounterOfMarks / COUNT_OF_MARKS;
          SlistOfStudents *ppNewElement = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
          pNewElement->m_pNext = ppNewElement;
          pNewElement = ppNewElement;

          nNumOfStudents++;
      } while (nSymbol = (fgetc(fp)) != EOF);
      if(pNewElement)
      fclose(fp);
      pNewElement->m_pNext = NULL;
}


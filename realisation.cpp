#include "realisation.h"

int AddStudent(SlistOfStudents **ppNode) {
    int nIsTrue = 0;
    SlistOfStudents *pNewElemet = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
    if (!pNewElemet){
        printf("It`s impossible to allocate memory\n");
        return 0;
    }
    printf("Enter your students as in the example");
    printf("\n+--------------------------------------+\n");
    printf("  Zubenko Michail 24 12 2002 3 4 4 5 2  ");
    printf("\n+--------------------------------------+\n");


    printf("Surname: \n");
    fscanf(stdin, "%s", pNewElemet->m_chSurname);
    for (int i = 0; i < strlen(pNewElemet->m_chSurname); ++i) {
        while (!isalpha(pNewElemet->m_chSurname[i]))
        {
            i = 0;
            printf("Surname: \n");
            printf("You entered incorrect surname for student. Please enter only words. For example: Roman. \n");
            fscanf(stdin, "%s", pNewElemet->m_chSurname);
        }
    }

    printf("Name: \n");
    fscanf(stdin, "%s", pNewElemet->m_chName);
    for (int i = 0; i < strlen(pNewElemet->m_chName); ++i) {
        while (!isalpha(pNewElemet->m_chName[i]))
        {
            i = 0;
            printf("Name: \n");
            printf("You entered incorrect surname for student. Please enter only words. For example: Roman. \n");
            fscanf(stdin, "%s", pNewElemet->m_chName);
        }
    }

    char chTemp[20];
    while (true) {
        printf("Day: \n");
        scanf("%s", &chTemp);
        if (atoi(chTemp) >= 1 && atoi(chTemp) <= 31) {
            pNewElemet->m_nDay = atoi(chTemp);
            break;
        }
        else
        {
            printf("You entered incorrect day of birth in student \n");
            continue;
        }
        break;
    }

    while (true) {
        printf("Month: \n");
        scanf("%s", &chTemp);
        if (atoi(chTemp) >= 1 && atoi(chTemp) <= 12) {
            pNewElemet->m_nMonth = atoi(chTemp);
            break;
        }
        else
        {
            printf("You entered incorrect month of birth in student \n");
            continue;
        }
        break;
    }

    while (true) {
        printf("Year: \n");
        scanf("%s", &chTemp);
        if (atoi(chTemp) >= 1970 && atoi(chTemp) <= 2004) {
            pNewElemet->m_nYear = atoi(chTemp);
            break;
        }
        else
        {
            printf("You entered incorrect year of birth in student \n");
            continue;
        }
        break;
    }

    int iTemp = 0;
    int iCouner = 0;
    double dCounterOfMarks = 0;
    for (int i = 0; i < 5; i++) {
        printf("Type your marks %i : \n", i);
        scanf("%s", chTemp);
        if (atoi(chTemp) <= 5 && atoi(chTemp) > 1)
        {
            pNewElemet->m_nMarks[i] = atoi(chTemp);
            dCounterOfMarks += pNewElemet->m_nMarks[i];
            iTemp = i;
        }
        else
        {
            if (i == 0)
            {
                iTemp = -1;
                i = iTemp;
            }
            else {
                i = iTemp;
            }
            printf("You entered incorrect mark in student \n");
        }
    }

    pNewElemet->m_fltAverage = dCounterOfMarks / COUNT_OF_MARKS;

    if (!*ppNode) {
        *ppNode = pNewElemet;
        pNewElemet->m_pNext = NULL;
        return 0;
    }
    pNewElemet->m_pNext = (*ppNode);
    *ppNode = pNewElemet;

}
//--------------------------------------------------------------------------------

int ReadFromKeyboard(SlistOfStudents **ppNode) {
    SlistOfStudents *pList = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
    do {
        int nAnswer = 0;
        printf("If you want to stop writing enter some sign, if you want to continue writing enter 1 : ");
        scanf("%d", &nAnswer);
        if (nAnswer != 1) break;
        printf("Enter your students as in the example");
        printf("\n+--------------------------------------+\n");
        printf("  Zubenko Michail 24 12 2002 3 4 4 5 2  ");
        printf("\n+--------------------------------------+\n");

        if (!(*ppNode)) {

            (*ppNode) = pList;
        }

        double dCounterOfMarks = 0;

        printf("Surname: \n");
        fscanf(stdin, "%s", pList->m_chSurname);
        for (int i = 0; i < strlen(pList->m_chSurname); ++i) {
            while (!isalpha(pList->m_chSurname[i]))
            {
                i = 0;
                printf("Surname: \n");
                printf("You entered incorrect surname for student. Please enter only words. For example: Roman. \n");
                fscanf(stdin, "%s", pList->m_chSurname);
            }
        }

        printf("Name: \n");
        fscanf(stdin, "%s", pList->m_chName);
        for (int i = 0; i < strlen(pList->m_chName); ++i) {
            while (!isalpha(pList->m_chName[i]))
            {
                i = 0;
                printf("Name: \n");
                printf("You entered incorrect surname for student. Please enter only words. For example: Roman. \n");
                fscanf(stdin, "%s", pList->m_chName);
            }
        }

        char chTemp[20];
        while (true) {
            printf("Day: \n");
            scanf("%s", &chTemp);
            if (atoi(chTemp) >= 1 && atoi(chTemp) <= 31) {
                pList->m_nDay = atoi(chTemp);
                break;
            }
            else
            {
                printf("You entered incorrect day of birth in student \n");
                continue;
            }
            break;
        }

        while (true) {
            printf("Month: \n");
            scanf("%s", &chTemp);
            if (atoi(chTemp) >= 1 && atoi(chTemp) <= 12) {
                pList->m_nMonth = atoi(chTemp);
                break;
            }
            else
            {
                printf("You entered incorrect month of birth in student \n");
                continue;
            }
            break;
        }

        while (true) {
            printf("Year: \n");
            scanf("%s", &chTemp);
            if (atoi(chTemp) >= 1970 && atoi(chTemp) <= 2004) {
                pList->m_nYear = atoi(chTemp);
                break;
            }
            else
            {
                printf("You entered incorrect year of birth in student \n");
                continue;
            }
            break;
        }

        int iTemp = 0;
        int iCouner = 0;
        for (int i = 0; i < 5; i++) {
            printf("Type your marks %i : \n", i);
            scanf("%s", chTemp);
            if (atoi(chTemp) <= 5 && atoi(chTemp) > 1)
            {
                pList->m_nMarks[i] = atoi(chTemp);
                dCounterOfMarks += pList->m_nMarks[i];
                iTemp = i;
            }
            else
            {
                if (i == 0)
                {
                    iTemp = -1;
                    i = iTemp;
                }
                else {
                i = iTemp;

                }
                printf("You entered incorrect mark in student \n");
            }
        }

        pList->m_fltAverage = dCounterOfMarks / COUNT_OF_MARKS;
        SlistOfStudents *pp = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
        pList->m_pNext = pp;
        pList = pp;

    } while (1);

    pList->m_pNext = NULL;
    return 1;
}
//--------------------------------------------------------------------------------

int isEmpetyFile(const char* pRootName)
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
//--------------------------------------------------------------------------------

int ReadFromFile(const char *pRootName, SlistOfStudents **ppNode)
{
    FILE *fp;
    if (!(fp = fopen(pRootName, "r+"))) {
        printf("You entered wrong file name");
        fclose(fp);
        return 0;
    }

    SlistOfStudents *pNewElement = (SlistOfStudents*)malloc(sizeof(SlistOfStudents));
    int nSymbol;
    int nNumOfStudents = 1;
    int size;

    if (!isEmpetyFile(pRootName))
    {
        return 0;
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
                return 0;
            }
        }
        fscanf(fp, "%s", pNewElement->m_chName);
        for (int i = 0; i < strlen(pNewElement->m_chName); ++i) {
            if (!isalpha(pNewElement->m_chName[i])) {
                printf("You read incorrect name in %d student", nNumOfStudents);
                return 0;
            }
        }

        fscanf(fp, "%d", &pNewElement->m_nDay);
        for (int i = 1; i <= 31; ++i) {
            if (pNewElement->m_nDay == i)
                isTrue++;
        }
        if (isTrue != 1) {
            printf("You read incorrect day of birth in %d student", nNumOfStudents);
            return 0;
        }

        fscanf(fp, "%d", &pNewElement->m_nMonth);
        for (int i = 1; i <= 12; ++i) {
            if (pNewElement->m_nMonth == i)
                isTrue++;
        }
        if (isTrue != 2) {
            printf("You read incorrect month of birth in %d student", nNumOfStudents);
            return 0;
        }

        fscanf(fp, "%d", &pNewElement->m_nYear);
        for (int i = 1970; i <= 2020; ++i) {
            if (pNewElement->m_nYear == i)
                isTrue++;
        }
        if (isTrue != 3) {
            printf("You read incorrect year of birth in %d student", nNumOfStudents);
            return 0;
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
            return 0;
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
//--------------------------------------------------------------------------------

void Print5StudentsWithWorstMarks(SlistOfStudents *pNode)
{
    SlistOfStudents* pTemp = pNode;
    int nNumOfStudents = 0;
    while (pTemp->m_pNext != NULL) {

        nNumOfStudents++;
        pTemp = pTemp->m_pNext;
    }
    if (nNumOfStudents < 5)
    {
        printf("Your list is too small\n");
        return;
    }
    printf("\n");
    printf("\n");
    printf("\n+-----------------------------------------------------------------------------------------+\n");
    printf("|                     LIST OF 5 STUDENTS WITH THE WORST AVERAGE MARK                      |");
    printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");
    printf("| Number|      NAME AND SURNAME    |DATE OF BIRTH|          MARKS        |  AVERAGE MARKS |");
    printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");

      nNumOfStudents = 0;
    while (nNumOfStudents < 5) {
        printf("|");
        printf("%6d |%12s %12s ", nNumOfStudents, pNode->m_chSurname, pNode->m_chName);

        printf("| %02i.%02i.%4i  |", pNode->m_nDay, pNode->m_nMonth, pNode->m_nYear);
        for (int j = 0; j < 5; j++)
            printf("%2i | ", pNode->m_nMarks[j]);
        printf("     %3.1lf       |", pNode->m_fltAverage);
        printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");
        pNode = pNode->m_pNext;
        nNumOfStudents++;
    }
    printf("\n");
    printf("\n");
}
//--------------------------------------------------------------------------------

void PrintData(SlistOfStudents *pNode) {
    printf("\n");
    printf("\n");
    printf("\n+-----------------------------------------------------------------------------------------+\n");
    printf("|                                   LIST OF STUDENTS                                      |");
    printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");
    printf("| Number|      NAME AND SURNAME    |DATE OF BIRTH|          MARKS        |  AVERAGE MARKS |");
    printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");

    int nNumberOfStudents = 0;
    while (pNode->m_pNext != NULL) {
        printf("|");
        printf("%6d |%12s %12s ", nNumberOfStudents, pNode->m_chSurname, pNode->m_chName);

        printf("| %02i.%02i.%4i  |", pNode->m_nDay, pNode->m_nMonth, pNode->m_nYear);
        for (int j = 0; j < 5; j++)
            printf("%2i | ", pNode->m_nMarks[j]);
        printf("     %3.1lf       |", pNode->m_fltAverage);
        printf("\n+-------+--------------------------+-------------+-----------------------+----------------+\n");
        pNode = pNode->m_pNext;
        nNumberOfStudents++;
    }
    printf("\n");
    printf("\n");
}
//--------------------------------------------------------------------------------

SlistOfStudents *PreviousStudent(SlistOfStudents *pNode, SlistOfStudents *pItem){
    if (pItem == pNode)
        return NULL;
    SlistOfStudents* pNewElement;
    for (pNewElement = pNode; pNewElement->m_pNext != pItem; pNewElement = pNewElement->m_pNext);

    return pNewElement;
}
//--------------------------------------------------------------------------------

void SortAndPrint5StudentsWithWorstMarks(SlistOfStudents **ppNode){
    SlistOfStudents *pNewElement, *pNewElementNext, *pNewElementPrevious1, *pNewElementPrevious2, *pTemp;

    for (pNewElement = *ppNode; pNewElement->m_pNext; pNewElement = pNewElement->m_pNext){
        for (pNewElementNext = pNewElement->m_pNext; pNewElementNext->m_pNext; pNewElementNext = pNewElementNext->m_pNext)
        {
            pNewElementPrevious1 = PreviousStudent(*ppNode, pNewElement);
            pNewElementPrevious2 = PreviousStudent(*ppNode, pNewElementNext);
            if (pNewElement->m_fltAverage > pNewElementNext->m_fltAverage)
            {
                if (pNewElement->m_pNext == pNewElementNext)
                {
                    pTemp = pNewElementNext->m_pNext;
                    pNewElementNext->m_pNext = pNewElement;
                    pNewElement->m_pNext = pTemp;
                } else {
                    pTemp = pNewElementNext->m_pNext;
                    pNewElementNext->m_pNext = pNewElement->m_pNext;
                    pNewElement->m_pNext = pTemp;
                    pNewElementPrevious2->m_pNext = pNewElement;
                }
                if (!pNewElementPrevious1) {
                    *ppNode = pNewElementNext;
                } else {
                    pNewElementPrevious1->m_pNext = pNewElementNext;

                }
                pTemp = pNewElement;
                pNewElement = pNewElementNext;
                pNewElementNext = pTemp;
            }
        }
    }

    Print5StudentsWithWorstMarks(*ppNode);
}
//--------------------------------------------------------------------------------

void SortBySurname(SlistOfStudents **ppHead)
{
    SlistOfStudents *pNewElement, *pNewElementNext, *pNewElementPrevious1, *pNewElementPrevious2, *pTemp;

    for (pNewElement = *ppHead; pNewElement->m_pNext; pNewElement = pNewElement->m_pNext) {
        for (pNewElementNext = pNewElement->m_pNext; pNewElementNext->m_pNext; pNewElementNext = pNewElementNext->m_pNext) {
            pNewElementPrevious1 = PreviousStudent(*ppHead, pNewElement);
            pNewElementPrevious2 = PreviousStudent(*ppHead, pNewElementNext);
            if (strcmp(pNewElement->m_chSurname, pNewElementNext->m_chSurname) < 0) {
                if (pNewElement->m_pNext == pNewElementNext) {
                    pTemp = pNewElementNext->m_pNext;
                    pNewElementNext->m_pNext = pNewElement;
                    pNewElement->m_pNext = pTemp;
                } else {
                    pTemp = pNewElementNext->m_pNext;
                    pNewElementNext->m_pNext = pNewElement->m_pNext;
                    pNewElement->m_pNext = pTemp;
                    pNewElementPrevious2->m_pNext = pNewElement;
                }
                if (!pNewElementPrevious1)
                {
                    *ppHead = pNewElementNext;

                } else {
                    pNewElementPrevious1->m_pNext = pNewElementNext;
                }
                pTemp = pNewElement;
                pNewElement = pNewElementNext;
                pNewElementNext = pTemp;
            }
        }
    }
}
//--------------------------------------------------------------------------------


void DeleteStudentsWithWMarksTwo(SlistOfStudents **ppGroup) {

    SlistOfStudents *NewElementPrevious = NULL, *pNewElementCurrent = *ppGroup;

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

int SaveInFile(SlistOfStudents *pNode) {
    printf("Do you want to save your data into file?? \n");
    printf("Enter 1 if you want or any other character if not\n");
    int nAnswer;
    scanf("%d", &nAnswer);
    if (nAnswer != 1) {
        return 0;
    }
    printf("Enter name of file: ");
    char chName[SIZE_OF_NAME];
    scanf("%s", chName);
    strcat(chName, ".txt");
    FILE* fp;
    fp = fopen(chName, "w+");
    while (pNode->m_pNext) {


        fprintf(fp, "%s ", pNode->m_chSurname);
        fprintf(fp, "%s ", pNode->m_chName);
        fprintf(fp, "%d ", pNode->m_nDay);
        fprintf(fp, "%d ", pNode->m_nMonth);
        fprintf(fp, "%d ", pNode->m_nYear);
        for (int i = 0; i < COUNT_OF_MARKS; i++)
        {
            fprintf(fp, "%d ", pNode->m_nMarks[i]);
        }
        fprintf(fp, "%.1f \n", pNode->m_fltAverage);
        pNode = pNode->m_pNext;
    }
    fclose(fp);
}
//--------------------------------------------------------------------------------

int InputMenu(SlistOfStudents **ppNode) {
    printf("\n\n+-----------+--------------------------+\n");
    printf("|   Choice  |          Actions         |\n");
    printf("+-----------+--------------------------+\n");
    printf("|      1    |     To read from file    |\n");
    printf("+-----------+--------------------------+\n");
    printf("|      2    |   To read from keyboard  |\n");
    printf("+-----------+--------------------------+\n");
    printf("|      0    |    To exit the program   |\n");
    printf("+-----------+--------------------------+\n");

    int nAnswer; scanf("%d", &nAnswer);

    switch (nAnswer)  {
        case 1:
            if (!ReadFromFile("list.txt", ppNode)) return 0;
            break;
        case 2:
            if (!ReadFromKeyboard(ppNode)) return 0;
            break;
        default:
            printf("You close the program");
            return 0;
    }
    printf("\n\n");
}
//--------------------------------------------------------------------------------

int MainMenu(SlistOfStudents** ppNode) {
    printf("\n");
    printf("\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|   Choice  |     Actions                                              |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      1    |     To print Data                                        |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      2    |     To sort by surname                                   |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      3    |     To show 5 stuudents with the worst average mark      |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      4    |     To delete students with marks 2 and close program    |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      5    |     To add new student                                   |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("|      0    |     To exit the program                                  |\n");
    printf("+-----------+----------------------------------------------------------+\n");
    printf("\n");
    printf("\n");

    int nAnswer;
    scanf("%d", &nAnswer);

    switch (nAnswer) {
        case 1:
            PrintData(*ppNode);
            break;
        case 2:
            SortBySurname(ppNode);
            break;
        case 3:
            SortAndPrint5StudentsWithWorstMarks(ppNode);
            break;
        case 4:
            DeleteStudentsWithWMarksTwo(ppNode);
            PrintData(*ppNode);
            return 0;
            break;
        case 5:
            AddStudent(ppNode);
            break;
        case 0:
            printf("You close the program");
            return 0;
        default:
            printf("You close the program");
            return 0;
    }
}


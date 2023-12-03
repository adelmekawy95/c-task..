/********************************************************* Documentation ****************************************************
**
*******************************************************************************************************************************
*		File:
*		Author:  		Ahmed Nada & Adel & Mohamed & Abdelrahman & Mohamed Hisham
*		Data:  			12/3/2024
*		notes:-  all done as discriped except for writting and reading text file & also we noticed at late time that we supposed
                        to create different .c files as we integrated all functions in one file
********************************************************************************************************************************
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************* MACROS section *******************************************************/

#define ADD_NEW_STUDENT 1
#define DELETE_STUDENT 2
#define Display_Students 3
#define Exit 4

#define NotTaken 0
#define Taken 1
/*******************************************************************************************************************************/

/*************************************************************** Structures ****************************************************/
typedef struct Record
{
    char Name[30];
    char Gender[10];
    int Age, Id, Acadimic_year, Vacency;

} Student_Record;
/*******************************************************************************************************************************/
/********************************************************* Global varibles section *********************************************/
Student_Record Students_data[100]; // array of students data
int iterator = 0;
/*******************************************************************************************************************************/

/********************************************************* Functions prototype section *****************************************/
int CheckOnId(int Id);
/*******************************************************************************************************************************/

/********************************************************* main program  *******************************************************/
int main()
{
    /*Local Varibles*/
    int Choise = 0; // varible to store user choice into it and giving it intial varible zero to make sure what number does it store
    int Exit_IdLoop = Taken;
    int out = 0;

    // getting the instant data at the following varible
    char TempStudent_name[30], TempStudent_Gender[5];
    int TempStudent_Age, TempStudent_Id, TempStudent_AcadimicYear;
    Student_Record *temp_student_data = (Student_Record *)malloc(sizeof(Student_Record));

    while (1)
    {
        system("cls"); // clear the cmd
        /* getting the choice from the user*/
        printf("welcome......\n");
        printf("To add new student please enter %d \n", ADD_NEW_STUDENT);
        printf("To delete exisiting student please enter %d \n", DELETE_STUDENT);
        printf("To display all student please enter %d \n", Display_Students);
        printf("To Exit program please enter %d\n", Exit);
        scanf("%d", &Choise);
        system("cls"); // clear cmd
        /*Acting based on the user's choice*/
        switch (Choise)
        {
        case ADD_NEW_STUDENT:
            system("cls"); // clear the command line

            printf("Please enter the student Name\n");
            scanf("%s", &TempStudent_name);
            system("cls"); // clear the command line

            printf("please enter the student Gender... enter m for male and f for female \n");
            scanf("%s", &TempStudent_Gender);
            system("cls"); // clear the command line

            printf("Please enter the student age\n");
            scanf("%d", &TempStudent_Age);
            while (TempStudent_Age > 30)
            {
                system("cls"); // clear the command line
                printf("the maximum allowable age is 30\n");
                printf("please reenter the age in the right range\n");
                scanf("%d", &TempStudent_Age);
            }
            system("cls"); // clear the command line

            printf("Please enter the student acadimic year\n");
            scanf("%d", &TempStudent_AcadimicYear);
            while (TempStudent_AcadimicYear > 5)
            {
                system("cls"); // clear the command line
                printf("the maximum allowable acadimic year is 5\n");
                printf("please reenter the acadimic in the right range\n");
                scanf("%d", &TempStudent_AcadimicYear);
            }
            system("cls"); // clear the command line

            printf("Please enter the Student Id\n");
            scanf("%d", &TempStudent_Id);
            Exit_IdLoop = CheckOnId(TempStudent_Id);
            while (Exit_IdLoop == Taken)
            {
                system("cls");
                printf("Id is already taken\n");
                printf("please renter the id\n");
                scanf("%d", &TempStudent_Id);
                Exit_IdLoop = CheckOnId(TempStudent_Id);
            }
            system("cls"); // clear the command line

            for (iterator = 0; iterator < 100; iterator++)
            {
                if (Students_data[iterator].Vacency == NotTaken)
                {
                    strcpy((Students_data[iterator].Name), TempStudent_name);
                    strcpy((Students_data[iterator].Gender), TempStudent_Gender);
                    Students_data[iterator].Age = TempStudent_Age;
                    Students_data[iterator].Acadimic_year = TempStudent_AcadimicYear;
                    Students_data[iterator].Id = TempStudent_Id;
                    Students_data[iterator].Vacency = Taken;
                    break;
                }
            }
            break;
        case DELETE_STUDENT:
            system("cls");
            printf("please enter the id\n");
            scanf("%d", &TempStudent_Id);
            Exit_IdLoop = CheckOnId(TempStudent_Id);
            printf("%d", Exit_IdLoop);
            while (Exit_IdLoop == NotTaken)
            {
                printf("Id dosen't exist\n");
                printf("please reenter a valid Id\n");
                scanf("%d", &TempStudent_Id);
                Exit_IdLoop = CheckOnId(TempStudent_Id);
            }
            Students_data[iterator].Id = 0;
            Students_data[iterator].Vacency = NotTaken;
            break;
        case Display_Students:
            printf("Student Name    Student Id      Student Age     Student Acadimic Year       Student Gender\n");
            for (int i = 0; i < 100; i++)
            {
                if (Students_data[i].Vacency == Taken)
                {
                    printf("%s              %d                  %d                  %d                          %s\n", Students_data[i].Name, Students_data[i].Id, Students_data[i].Age, Students_data[i].Acadimic_year, Students_data[i].Gender);
                }
            }
            printf("enter any number to continue\n");
            scanf("%d");
            break;
        case Exit:
            out = 1;
            break;
        default:
            break;
        }
        if (out == 1)
        {
            break;
        }
    }

    return 0;
}
/*******************************************************************************************************************************/

/********************************************************* Functions implementation section ************************************/
int CheckOnId(int Id)
{
    int loc_returnedValue = NotTaken;
    for (int loc_iterator = 0; loc_iterator < 100; loc_iterator++)
    {
        if (Id == Students_data[loc_iterator].Id)
        {
            loc_returnedValue = Taken;
            Students_data[loc_iterator].Vacency = Taken;
            iterator = loc_iterator;
        }
    }
    return loc_returnedValue;
}
/*******************************************************************************************************************************/

/********************************************************* History Log ****************************************************
**
*******************************************************************************************************************************
*	User 							Date								Brief
*****************************************************************************************
*   Ahmed & Adel                                                              creating Add new student
*abdelrahman & Mohamed                                                           creat delete student
* Mohamed & Hosni                                                                 Exit & display all students
*********************************************************************************************************************************
**
*/
//Employee Management System

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

struct employee
{
    char name[50];
    int age;
    char email[50];
    char contactNo[50];
    char salary[50];
    struct employee *link;
};

typedef struct employee emp;
emp *head=NULL, *last=NULL;


COORD coord = {0,0};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void insert(emp **head,char Emp[],int Age,char Email[],char Sal[],char contact[])
{

    emp *temp = malloc(sizeof(emp));
    strcpy(temp->name,Emp);
    strcpy(temp->salary,Sal);
    strcpy(temp->email,Email);
    strcpy(temp->contactNo,contact);
    temp->age=Age;
    temp->link = NULL;
    emp *p = *head;
    if(*head ==NULL)
    {
        *head = temp;
        return;
    }
    while(p->link!=NULL)
    {
        p = p->link;
    }
    p->link = temp;

}

void rec_list(emp *head)
{
    gotoxy(80,3);
    printf("==========***Employee List***==========\n\n");
    int flag=0;
    emp *p = head;
    printf("______________________________________________________________________________________");
    printf("________________________________________________________________");
    printf("_______________________________________________");
    gotoxy(1,7);
    printf("Sl.");
    gotoxy(15,7);
    printf("Name");
    gotoxy(34,7);
    printf("Age");
    gotoxy(69,7);
    printf("Email");
    gotoxy(112,7);
    printf("Contact No");
    gotoxy(158,7);
    printf("Salary\n");
    printf("______________________________________________________________________________________");
    printf("________________________________________________________________");
    printf("_______________________________________________\n");
    int l=7;
    int i=0;
    while (p != NULL)
    {
        ++i;
        l=l+3;
        gotoxy(1,l);
        printf("%d",i);
        gotoxy(15,l);
        printf("%s ",p->name);
        gotoxy(34,l);
        printf("%d",p->age);
        gotoxy(67,l);
        printf("%s",p->email);
        gotoxy(112,l);
        printf("%s",p->contactNo);
        gotoxy(158,l);
        printf("%s\n",p->salary);

        p = p->link;
        flag++;
    }

    if(flag==0)
    {
        printf("\n\n No data found\n");
    }
}


void delete_rec(emp **head)
{
    char name[30];
    int count=0;
    emp *temp = *head;
    emp *p=NULL;
    printf("\n\t\t\t\t\t\t\t  ~~~~> Deletion Section <~~~~ \n\t\t\t\t\t\t\t  ____________________________\n ");
    printf("\n Enter name for deleting: ");

    scanf("%s",name);

    if(strcmp(temp->name,name)==0)
    {
        *head = temp->link;
        printf("\n %s's details have been deleted...\n ",temp->name);
        count++;
        free(temp);
        return;
    }
    while(temp->name!=NULL)
    {
        if(strcmp(temp->link->name,name)==0)
        {
            p = temp->link;
            temp->link = p->link;
            count++;
            printf("\n %s's details have been deleted...\n ",p->name);
            free(p);
            return;
        }
        temp = temp->link;
    }

}

void search(emp *head)
{
    char another;

    another = 'y';

    while(another == 'y')
    {

        system("cls");
        int count=0;
        char name[20];
        printf("\n\t\t\t\t\t\t\t  ~~~~> Searching Section <~~~~ \n\t\t\t\t\t\t\t  _____________________________\n ");
        printf("\n Enter employee name : ");
        fflush(stdin);
        scanf("%s",name);
        emp *ptr=head;

        while(ptr!=NULL)
        {

            if(strcmp(ptr->name,name)==0)
            {
                printf("\n Employee details: \n Name: %s \n Age: %d \n Email: %s \n Contact No: %s \n Salary: %s\n\n",ptr->name,ptr->age,ptr->email,ptr->contactNo,ptr->salary);
                count++;
            }
            ptr = ptr->link;
        }

        if (count==0)
        {
            printf("\n %s is not found",name);
        }
        printf("\n\n Press 'Y' to search another data. . .\n Press any key to skip . . .\n ");
        another = getche();


    }
}

void modify(emp **head)
{

    char name[20],N[20],S[20],EM[20],C[20];
    int A,count=0;
    gotoxy(90,0);
    printf("\n\t\t\t\t\t\t\t  ~~~~> Modification Section <~~~~ \n\t\t\t\t\t\t\t  __________________________________\n ");
    printf("\n Enter name to update employee details : ");
    fflush(stdin);
    scanf("%s",name);
    emp *ptr=*head;
    while(ptr!=NULL)
    {

        if(strcmp(ptr->name,name)==0)
        {
            printf("\n Employee details: \n 1. Name: %s \n 2. Age: %d \n 3. Email: %s \n 4. Contact No: %s \n 5. Salary: %s\n\n",ptr->name,ptr->age,ptr->email,ptr->contactNo,ptr->salary);
            printf("\n Choose a number to modify : \n");
            printf("\n 1. Modify Name.\n 2. Modify Age.\n 3. Modify Email.\n 4. Modify Contact No.\n 5. Modify Salary.\n\n ");
            count++;
            char choose;
            scanf("%s",&choose);
            switch(choose)
            {
            case '1':
                printf("\n Enter New name : ");
                fflush(stdin);
                scanf("%s",&N);
                strcpy(ptr->name,N);
                printf("\n Name has been modified...");
                getch();
                break;




            case '2':

                fflush(stdin);
                printf("\n Enter New age : ");
                scanf("%d",&A);
                ptr->age=A;

                printf("\n Age has been modified...");
                getch();

                break;

            case '3':
                printf("\n Enter New E-mail : ");
                fflush(stdin);
                scanf("%s",&EM);
                fflush(stdin);
                strcpy(ptr->email,EM);
                printf("\n Email has been modified...");
                getch();

                break;
            case '4':


                fflush(stdin);
                printf("\n Enter New Contact No : ");
                scanf("%s",&C);
                fflush(stdin);
                strcpy(ptr->contactNo,C);
                printf("\n Contact number has been modified...");
                getch();


                break;

            case '5':

                printf("\n Enter New Salary : ");
                fflush(stdin);
                scanf("%s",&S);

                strcpy(ptr->salary,S);
                printf("\n Salary has been modified...");
                getch();

                break;

            default:
                printf(" Invalid!");
                getch();
            }

        }

        ptr = ptr->link;

    }
    if (count==0)
    {
        printf(" No name has been found...\n\n ");
        system("pause");
    }
}

int total(emp *head)
{
    int count=0;
    emp *ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}

int main()
{
    system("color 0A");
    emp *head = NULL;
    int n;
    char choice;

    while(1)
    {
        system("cls");
        gotoxy(45,4);
        printf("====================================================");
        gotoxy(55,5);
        printf("Employees Management System");
        gotoxy(45,6);
        printf("====================================================");

        gotoxy(45,8);
        printf("1. Add Record");
        gotoxy(45,10);
        printf("2. List Records");
        gotoxy(45,12);
        printf("3. Modify Records");
        gotoxy(45,14);
        printf("4. Delete Records");
        gotoxy(45,16);
        printf("5. Search Records");
        gotoxy(45,18);
        printf("6. Number Of Employees");
        gotoxy(45,20);
        printf("7. Exit");
        gotoxy(45,22);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();

        switch(choice)
        {
        case '1':
            system("cls");
            printf("\n\t\t\t\t\t\t\t  ~~~~> Insertion Section <~~~~ \n\t\t\t\t\t\t\t  ____________________________\n ");
            char Emp[50];
            printf("\n Enter Employee Name: ");
            fflush(stdin);
            scanf("%s",&Emp);

            int Age;
            fflush(stdin);
            printf(" Enter Age: ");
            scanf("%d",&Age);

            char Email[50];
            printf(" Enter E-mail: ");
            fflush(stdin);
            scanf("%s",&Email);
            fflush(stdin);

            char Sal[50];
            printf(" Enter Salary: ");
            fflush(stdin);
            scanf("%s",&Sal);
            fflush(stdin);

            char contact[50];
            printf(" Enter Contact Number: ");
            fflush(stdin);
            scanf("%s",&contact);
            fflush(stdin);

            insert(&head,Emp,Age,Email,Sal,contact);
            printf("\n Details have been inserted. . .\n\n ");
            system("pause");
            break;
        case '2':
            system("cls");

            rec_list(head);
            printf("\n\n Enter any key to back to main menu ... ");
            getche();

            break;

        case '3':
            system("cls");
            modify(&head);

            break;
        case '4':

            system("cls");
            delete_rec(&head);
            system("pause");

            break;

        case '5':
            system("cls");
            search(head);

            break;

        case '6':

            system("cls");
            gotoxy(90,0);
            printf("\n\t\t\t\t\t\t\t  ~~~~> Total Employee Section <~~~~ \n\t\t\t\t\t\t\t  __________________________________\n ");
            printf(" Total Employees in the list: %d ",total(head));
            getch();

            break;

        case '7':
            exit(0);

        default:
            system("cls");
            printf("\n Invalid! Choose a correct Number...");
            getch();
            break;

        }

    }
    return 0;
}


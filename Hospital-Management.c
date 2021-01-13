//HOSPITAL MANAGEMENT SYSTEM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define seats 70

typedef struct type
{
    int age,total,paid;
    char name[25],gender[8],blood[4],doctor[25],disease[25],id[7];
    struct type *next;
}type;

void insert_end(type **head,char id[],char name[],char gender[],char blood[],int age,char disease[],char doctor[],int total,int paid)
{
    type *temp=malloc(sizeof(type));
    temp->age=age;
    temp->total=total;
    temp->paid=paid;
    strcpy(temp->id,id);
    strcpy(temp->name,name);
    strcpy(temp->gender,gender);
    strcpy(temp->blood,blood);
    strcpy(temp->doctor,doctor);
    strcpy(temp->disease,disease);
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    else
    {
        type *p=*head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        return;
    }
}
void print(type *head)
{

    while(head!=NULL)
    {

        printf("\t%s\t\t",head->id);
        printf("%s\t\t",head->name);
        printf("%s\t\t",head->gender);
        printf("%s\t\t",head->blood);
        printf("%d\t\t",head->age);
        printf("%s\t\t",head->disease);
        printf("%s\t\t",head->doctor);
        printf("%d\t\t\t",head->total);
        printf("%d\t\t",head->paid);
        printf("%d\n",(head->total - head->paid));
        printf("____________________________________________________");
        printf("____________________________________________________");
        printf("____________________________________________________");
        printf("____________________________________________________\n\n");
        head=head->next;
    }
    return;
}
void searchPrint(type *head,char sName[])
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    else if(head!=NULL)
    {
        while(head!=NULL)
        {
            if(strcmp((head->name),sName)==0)
            {
                printf("\t\t\t\t\t    Patient's Info.\n");
                printf("\t\t\t\t\t======================\n\n");
                printf("\t\t\tID           : %s\n",head->id);
                printf("\t\t\tName         : %s\n",head->name);
                printf("\t\t\tGender       : %s\n",head->gender);
                printf("\t\t\tBlood Group  : %s\n",head->blood);
                printf("\t\t\tAge          : %d\n",head->age);
                printf("\t\t\tDisease      : %s\n",head->disease);
                printf("\t\t\tDoctor       : %s\n\n",head->doctor);
                printf("\t\t\t\t\t    Account Section.\n");
                printf("\t\t\t\t\t======================\n\n");
                printf("\t\t\tTotal Amount : %d tk\n",head->total);
                printf("\t\t\tPaid         : %d tk\n",head->paid);
                printf("\t\t\tDue          : %d tk\n\n\n",(head->total - head->paid));
                return;
            }
            else if(head->next==NULL && strcmp((head->name),sName)!=0)
            {
                printf("\t\t\t\t\t\t\t\t\t\a  Patient's Data Not Found\n");
                return;
            }
            else
            {
                head=head->next;
            }

        }
    }

}

void release(type **head,char id[])
{
    type *temp,*p;
    temp=*head;
    p=temp;
    if(*head==NULL)
    {
        printf("Empty List\n");
        return;
    }

        while(temp!=NULL)
        {
            if(strcmp((*head)->id,id)==0)
            {
                *head=(*head)->next;
                free(temp);
                printf("\n\t\t\t\t\t\t\t\t\t   ID %s has been Deleted Successfully\n",id);
                return;
            }
            else if(strcmp(temp->id,id)==0)
            {
                p->next=temp->next;
                free(temp);
                printf("\n\t\t\t\t\t\t\t\t\t   ID %s has been Deleted Successfully\n",id);
                return;
            }

                p=temp;
                temp=temp->next;

        }

        printf("\t\t\t\t\t\t\t\t\t  __________\n");
        printf("\n\t\t\t\t\t\t\t\t\t   \aWrong ID\n");
        printf("\t\t\t\t\t\t\t\t\t  __________\n");
    }
int counter(type *head)
{
    int c=0;
    type *p=head;
    while(p!=NULL)
    {
        ++c;
        p=p->next;
    }
    return c;
}
void modify(type **head,char id[],int n)
{
    int age,total,paid;
    char name[25],gender[6],blood[4],doctor[25],disease[25];
    type *p=*head;

    if(p==NULL)
    {
        printf("\t\t\t\t\t\t\t\t\tEmpty List, can not be Modified.\n");
        return;
    }
    while(p!=NULL)
        {

            if(strcmp(p->id,id)==0)
            {
                switch(n)
                {
                    case 1:
                    {
                        printf("-->> ID : ");
                        fflush(stdin);
                        gets(id);
                        strcpy(p->id,id);
                        printf("\n\t\t\t\t\t\t\t\t\t   ID %s Modified  Successfully\n",id);
                        return;
                        break;
                    }
                    case 2:
                    {
                        printf("-->> Name : ");
                        fflush(stdin);
                        gets(name);
                        strcpy(p->name,name);
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 3:
                    {
                        printf("-->> Gender : ");
                        fflush(stdin);
                        gets(gender);
                        strcpy(p->gender,gender);
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 4:
                    {
                        printf("-->> Blood Group : ");
                        fflush(stdin);
                        gets(blood);
                        strcpy(p->blood,blood);
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 5:
                    {
                        printf("-->> Age : ");
                        scanf("%d",&age);
                        p->age=age;
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 6:
                    {
                        printf("-->> Disease : ");
                        fflush(stdin);
                        gets(disease);
                        strcpy(p->disease,disease);
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 7:
                    {
                        printf("-->> Doctor : ");
                        fflush(stdin);
                        gets(doctor);
                        strcpy(p->doctor,doctor);
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 8:
                    {
                        printf("-->> Total Amount : ");
                        scanf("%d",&total);
                        p->total=total;
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }
                    case 9:
                    {
                        printf("-->> Paid : ");
                        scanf("%d",&paid);
                        p->paid=paid;
                        printf("\n\t\t\t\t\t\t\t\t\t    Modified  Successfully\n");
                        return;
                        break;
                    }

                    default:
                    {
                       return;
                       break;
                    }

                }
            }
                p=p->next;
    }
    printf("\n\t\t\t\t\t\t\t\aNot found\n\t\t\t\t\t\t------------------------------\n");
}

int main()
{
    system("color 3F");
    type *head=NULL;
    int age,total,paid,total_seats=seats,m;
    char name[25],gender[8],blood[4],doctor[25],disease[25],id[6],sName[20];

    insert_end(&head,"AD200","Aseef","Male","O-",22,"poisoning","Dr.Babul",3000,900);
    insert_end(&head,"AD201","Tanvir","Male","AB+",26,"Headache","Dr.Habib",3500,1000);



int t=1;
char s,c;
    while(t)
    {
            printf("\n\n\t\t\t\t\t***Hospital Management***\n");
            printf("\t\t\t=========================================================\n");
            printf("\n\n\t\t\t\t\t\t\t\t\tMenu\n");
            printf("\t\t\t\t\t\t\t===================================\n\n");
            printf("\t\t\t\t\t\t\t1. Add New Patient\n");
            printf("\t\t\t\t\t\t\t2. Search Patient's Details\n");
            printf("\t\t\t\t\t\t\t3. Print Patient table\n");
            printf("\t\t\t\t\t\t\t4. Modify Patient's Info\n");
            printf("\t\t\t\t\t\t\t5. Release Patient\n");
            printf("\t\t\t\t\t\t\t6. Number of admitted Patients\n");
            printf("\t\t\t\t\t\t\t7. Available seats (Total 70)\n");
            printf("\t\t\t\t\t\t\t8. Exit\n");
            printf("\n\n\t\t\t------>>>Enter your choice : ");

            s = getch();
            printf("\n\n");
            system("cls");
        switch(s)
            {
            case '1':
                    {

                        printf("\n\nEnter New Patient's Detail : \n");
                        printf("===========================\n\n\n");

                        printf("-->> Enter Patient's Id : ");
                        fflush(stdin);
                        gets(id);
                        printf("-->> Enter Patient's Name : ");
                        fflush(stdin);
                        gets(name);
                        printf("-->> Enter Patient's Gender : ");
                        fflush(stdin);
                        gets(gender);
                        printf("-->> Enter Patient's Blood Group : ");
                        fflush(stdin);
                        gets(blood);
                        printf("-->> Enter Patient's Age : ");
                        scanf("%d",&age);
                        printf("-->> Enter Patient's Disease Name : ");
                        fflush(stdin);
                        gets(disease);
                        printf("-->> Enter Patient's Appointed Doctor : ");
                        fflush(stdin);
                        gets(doctor);
                        printf("-->> Enter Total Amount : ");
                        scanf("%d",&total);
                        printf("-->> Enter Paid Amount : ");
                        scanf("%d",&paid);
                        insert_end(&head,id,name,gender,blood,age,disease,doctor,total,paid);
                        printf("\n\n\t\t\t\t\t\t\t\t\tNew Patient Added Successfully");
                        system("pause");
                        system("cls");
                        break;
                    }

            case '2':
                {
                    fflush(stdin);
                    printf("\n\n-->> Enter Patient's Name For Info: ");
                    gets(sName);
                    printf("\n\n");
                    searchPrint(head,sName);
                    system("pause");
                    system("cls");
                    break;

                }
            case '3':
                {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  All Patient's Records: \n");
                        printf("\t\t\t\t\t\t\t============================================XXX");
                        printf("============================================\n\n");
                        printf("\t Id \t\t Name\t\t Gender \t Blood \t\t Age \t\tDisease \t\t Doctor \t\tTotal Amount \t\tPaid\t\tDue\n");
                        printf("____________________________________________________");
                        printf("____________________________________________________");
                        printf("____________________________________________________");
                        printf("____________________________________________________\n\n");
                        print(head);
                        system("pause");
                        system("cls");
                        break;

                }
             case '4':
            {


                while(1)
                {
                        printf("\n\t\t\t\t\tNote: [[[[[[   Enter \"0\" to stop modifing  ]]]]]]");
                        printf("\n\n-->> Enter Patient's ID to Modify : ");
                        fflush(stdin);
                        gets(id);
                        if(strcmp(id,"0")==0)
                        {
                            system("cls");
                             break;
                        }

                printf("\n\n\t\t\t\t\t\t\t\tSelect a number to Modify\n");
                printf("\t\t\t\t\t\t\t=======================================\n\n");
                printf("\t\t\t\t\t\t\t1.Id.\n");
                printf("\t\t\t\t\t\t\t2.Name.\n");
                printf("\t\t\t\t\t\t\t3.Gender.\n");
                printf("\t\t\t\t\t\t\t4.Blood Group.\n");
                printf("\t\t\t\t\t\t\t5.Age.\n");
                printf("\t\t\t\t\t\t\t6.Disease.\n");
                printf("\t\t\t\t\t\t\t7.Doctor.\n");
                printf("\t\t\t\t\t\t\t8.Total Amount.\n");
                printf("\t\t\t\t\t\t\t9.Paid.\n");
                printf("\n\n-->> Enter your choice : ");
                scanf("%d",&m);
                printf("\n");
                modify(&head,id,m);
                system("pause");
                system("cls");
                }
                break;

            }
            case '5':
                {
                    printf("\n\n-->> Enter Patient's ID to Delete Record : ");
                    fflush(stdin);
                    gets(id);
                    release(&head,id);

                    system("pause");
                    system("cls");
                    break;

                }
            case '6':
            {
                printf("\n\n\n\n-->> Number of Admitted Patients : %d\n\n",counter(head));
                system("pause");
                system("cls");
                break;

            }
            case '7':
                    {
                        printf("\n\n\n-->> Available Seats : %d\n\n",(total_seats-counter(head)));
                        system("pause");
                        system("cls");
                        break;

                    }
            case '8':
                {
                    t=0;
                    break;
                }
            default:
            {
                printf("\n\t\t\t\t\t\t\t  __________________________\n\t\t\t\t\t\t\t\a |You entered Invalid number|\n\t\t\t\t\t\t\t |__________________________|");
                printf("\nEnter a character to return-->>");
                getch();
                system("cls");
            }
        }
    }
    return 0;
}

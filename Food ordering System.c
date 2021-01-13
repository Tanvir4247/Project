#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct train
{
    char train[40];
    char place[50];
    char time[20];
    struct train *link;
} node;
node *head=NULL;
void insert(node **head,char Name[40],char Place[50],char Time[20])
{

    node *temp = malloc(sizeof(node));
    strcpy(temp->train,Name);
    strcpy(temp->place,Place);
    strcpy(temp->time,Time);
    temp->link = NULL;
    node *p = *head;
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
void rec_list(node *head)
{

    printf("\t\t\t\t\t\t\t\t==========***LIST***==========\n\n");
    int flag=0;
    node *p = head;

    printf("\nSl.");

    printf("\t\t\tTrain Name");

    printf("\t\t\tPlace");

    printf("\t\t\tTime\n\n");


    int i=725;
    while (p != NULL)
    {
        i=i+2;


        printf("\n%d",i);

        printf("\t\t\t%s ",p->train);

        printf("\t\t\t%s",p->place);

        printf("\t\t\t%s\n",p->time);

        p = p->link;
        flag++;
    }

    if(flag==0)
    {
        printf("\n\n No data found\n");
    }
}

void modify(node **head)
{

    char name[20],N[20],P[20],T[20],place[40];
    int A,count=0;

    printf("\n\t\t\t\t  ~~~~> Modification Section <~~~~ \n\t\t\t\t _________________________________\n ");
    printf("\n Enter Train Name to update: ");
    fflush(stdin);
    scanf("%s",name);
    printf("\n Enter Place to update: ");
    scanf("%s",place);
    node *ptr=*head;
    while(ptr!=NULL)
    {

        if(strcmp(ptr->train,name)==0)
        {

            if(strcmp(ptr->place,place)==0)
            {

                printf("\n Employee details: \n 1. Name: %s \n 2. Place: %s \n 3. Time: %s \n",ptr->train,ptr->place,ptr->time);
                printf("\n Choose a number to modify : \n");
                printf("\n 1. Modify Name.\n 2. Modify Place.\n 3. Modify Time.\n");
                count++;
                char choose;
                scanf("%s",&choose);
                switch(choose)
                {
                case '1':
                    printf("\n Enter New Name : ");
                    fflush(stdin);
                    scanf("%s",&N);
                    strcpy(ptr->train,N);
                    printf("\n Name has been modified...");
                    getch();
                    break;



                case '2':

                    fflush(stdin);
                    printf("\n Enter New Place : ");
                    scanf("%d",&P);
                    strcpy(ptr->place,P);

                    printf("\n Place has been modified...");
                    getch();

                    break;

                case '3':
                    printf("\n Enter New Time : ");
                    fflush(stdin);
                    scanf("%s",&T);
                    fflush(stdin);
                    strcpy(ptr->time,T);
                    printf("\n Time has been modified...");
                    getch();

                    break;

                default:
                    printf(" Invalid!");
                    getch();
                }

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





int main()
{
    node *head = NULL;
    int n;
    char choice;

    insert(&head,"Udayan","       Chittagong","5:30 - 5:32");
    insert(&head,"Udayan","       Laksham","3:30 - 4:30");
    insert(&head,"Udayan","       Feni","6:30 - 7:30");
    insert(&head,"Udayan","       Cumila","2:30 - 3:30");
    insert(&head,"Udayan","       Sylhet","2:30 - 3:30");

    insert(&head,"Meghna","       Chittagong","2:30 - 3:30");
    insert(&head,"Meghna","       Laksham","3:30 - 4:30");
    insert(&head,"Meghna","       Feni","6:30 - 7:30");
    insert(&head,"Meghna","       Cumila","2:30 - 3:30");
    insert(&head,"Meghna","       Sylhet","2:30 - 3:30");

    insert(&head,"Agnibina","Chittagong","2:30 - 3:30");
    insert(&head,"Agnibina","Laksham","3:30 - 4:30");
    insert(&head,"Agnibina","Feni","6:30 - 7:30");
    insert(&head,"Agnibina","Cumila","2:30 - 3:30");
    insert(&head,"Agnibina","Sylhet","2:30 - 3:30");

    while(1)
    {
        system("cls");

        printf("\t\t\t\t\t\t\tEastern Train Schedule");

        printf("\n===========================================================================================================");


        printf("\n\t\t\t\t1. Add Schedule ");

        printf("\n\t\t\t\t2. List Schedule");

        printf("\n\t\t\t\t3. Update Schedule");

        printf("\n\t\t\t\t4. Exit");

        printf("\n\t\t\t\tYour Choice: ");
        fflush(stdin);
        choice  = getche();

        switch(choice)
        {
        case '1':
            system("cls");
            printf("\n\t\t\t  ~~~> Insertion Section <~~~ \n\t\t\t ____________________________\n ");
            char Name[40];
            printf("\n Enter Train name: ");
            fflush(stdin);
            scanf("%s",&Name);

            char Place[50];
            printf("\n Enter Place name: ");
            fflush(stdin);
            scanf("%s",&Place);

            char Time[20];
            fflush(stdin);
            printf(" Enter Time: ");
            scanf("%d",&Time);
            fflush(stdin);
            insert(&head,Name,Place,Time);
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

        }

    }
    return 0;
}


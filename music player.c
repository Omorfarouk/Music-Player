#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addMusic(char name[], char artist[], int time);
void deleteMusic(char name[]);
void searchMusic(char name[]);
void sortMusic();
void displayMusic();
int  totalmusicNumber();

struct node{
    char name[50];
    char artist[50];
    int time;
    struct node *next;
};

struct node *head;

int main()
{
    int ch;
    char name[20];
    char artist[20];
    int time;
    while(1)
    {   
        printf("\n");
        printf("1.Add Music\n");
        printf("2.Delete music\n");
        printf("3.Search music\n");
       printf("4.Sort music\n");
       printf("5.Display  music\n");
       printf("6.Total music number\n");
       printf("7.exit\n\n");
       printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        { 
            int len;
            case 1:
                printf("\n\nEnter the Music Name: ");
				  fflush(stdin);
                scanf("%s",name);
                printf("Enter Artist Name: ");
				  fflush(stdin);
                scanf("%s",artist);
                printf("Enter music duration: ");
				  fflush(stdin);
                scanf("%d",&time);
                addMusic(name,artist,time);
                break;
            case 2:
                printf("Enter Name to delete music: ");
                scanf("%s",name);
                deleteMusic(name);
                break;
            case 3:
                searchMusic(name);
                break;
            case 4:
                sortMusic();
                break;
            case 5:
                displayMusic();
                break;
                case 6:
                len= totalmusicNumber();
                printf("total music= %d",len);
               
                break;
            case 7:
                exit(0);
        }
        printf("\n");
    }
    return 0;
}

void addMusic(char name[], char artist[], int time)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    strcpy(temp->artist,artist);
    temp->time = time;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void deleteMusic(char name[])
{
    struct node *prev = head;
    if(head == NULL)
    {
        printf("No Music Available\n");
        return;
    }
    if(strcmp(head->name,name) == 0)
    {
        head = head->next;
        free(prev);
        printf("Deleted Successfully\n");
        return;
    }
    else
    {
        struct node *temp = head->next;
        while(temp != NULL)
        {
            if(strcmp(temp->name,name) == 0)
            {
                prev->next = temp->next;
                free(temp);
                printf("Deleted Successfully\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Music not Found\n");
}

void searchMusic(char name[])
{ 
    char nam[50];
     printf("Enter Name: ");
                scanf("%s",nam);
    if(head == NULL)
    {
        printf("No Music Available\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->name,nam) == 0)
        { 
         printf("\nName: %s\n",temp->name);
         printf("Artist: %s\n",temp->artist);
         printf("Time: %d",temp->time);
            return;
        }
        temp = temp->next;
        }
        printf("Music not Found\n");
    }
    
void sortMusic()
{
    struct node *temp = head;
    struct node *temp1;
    struct node *temp2;
    char tem[20];
    int t;
    while(temp != NULL)
    {
        temp1 = temp->next;
        while(temp1 != NULL)
        {
            if(strcmp(temp->name,temp1->name) > 0)
            {
                strcpy(tem,temp->name);
                strcpy(temp->name,temp1->name);
                strcpy(temp1->name,tem);
                strcpy(tem,temp->artist);
                strcpy(temp->artist,temp1->artist);
                strcpy(temp1->artist,tem);
                t = temp->time;
                temp->time = temp1->time;
                temp1->time = t;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

void displayMusic()
{
    if(head == NULL)
    {
        printf("No Music Available\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("\nName: %s\n",temp->name);
        printf("Artist: %s\n",temp->artist);
        printf("Time: %d\n",temp->time);
        printf("\n");
        temp = temp->next;
    }
}

int totalmusicNumber(){
int count=0;
struct node *temp;
temp=head;
while (temp!=NULL)
{
    count++;
    temp=temp->next;
}
return count;
}

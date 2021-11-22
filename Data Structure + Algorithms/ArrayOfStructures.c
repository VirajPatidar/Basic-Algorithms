#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct student
{
    char name[50];
    int rollno;
} s[10];
void insert()
{
    printf("Enter the roll number ");
    scanf("%d",&s[count].rollno);
    printf("Enter the name ");
    scanf(" %[^\n]s",&s[count].name);
 }
void display()
{
    int i;
    for (i=0; i<count; i++)
    {
        printf("\nRoll number: %d",s[i].rollno);
        printf(" Name: ");
        puts(s[i].name);
    }
    printf("\n");
}
void search(int r)
{
    int i,flag=0;
    for (i=0; i<10; i++)
    {
        if(r==s[i].rollno)
        {
            printf("Name: ");
            puts(s[i].name);
            printf("\n");
            flag=1;
            break;
        }
    }
    if(flag=0)
        printf("Not found\n");
}
void delete(int roll)
{
    int i,flag=0;
    for (i=0; i<10; i++)
    {
        if (roll==s[i].rollno)
        {
            printf("Name: ");
            puts(s[i].name);
            s[i].rollno = 0;
            strcpy(s[i].name,"");
            printf("Record Deleted Successfully\n");
            flag=1;
            break;

        }
    }
    if(flag=0)
        printf("Not found\n");
}
void main()
{
    int choice;
    int delno;
    int roll;
    printf("\t\tMENU");
    printf("\n-------------------------------------\n");
    printf("PRESS 1.insert");
    printf("\nPRESS 2.Display");
    printf("\nPRESS 3.Delete");
    printf("\nPRESS 4.Search");
    printf("\nPRESS 5.TO EXIT.");
    printf("\n-------------------------------------\n");
    do
    {
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
          {
               case 1:insert();
                      count++;
                      break;
               case 2:display();
                      break;
               case 3:printf("Enter the roll number to delete the record ");
                      scanf("%d",&delno);
                      delete(delno);
                      break;
               case 4:printf("Enter the roll number to search for a record ");
                      scanf("%d",&roll);
                      search(roll);
                      break;
          }
    }while(choice != 5);
}

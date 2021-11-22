#include<stdlib.h>
#include <stdio.h>
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
void main()
{
        int choice,val,pos,data;
        while(1){

                printf("\n                MENU  \n");
                printf(" 1.Create     \n");
                printf(" 2.Display    \n");
                printf(" 3.Insert at the beginning    \n");
                printf(" 4.Insert at specified position \n");
                printf(" 5.Delete at specified position  \n");
                printf(" 6.Exit       \n");
                printf("----------------------\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         createSLL();
                                        break;
                        case 2:         display();
                                        break;
                        case 3:         printf("Enter the data value for the node:" );
                                        scanf("%d",&val);
                                        insertBegin(val);
                                        break;
                        case 4:         printf("Enter the value of the node after which new node is to be inserted: ");
                                        scanf("%d",&pos);
                                        printf("Enter the data value of the new node: ");
                                        scanf("%d",&data);
                                        insertAfter(pos,data);
                                        break;
                        case 5:         printf("Enter the value of the node before which, the node is to be deleted: ");
                                        scanf("%d",&pos);
                                        deleteBefore(pos);
                                        break;
                        case 6:         exit(0);
                                        break;
                        default:        printf("n Wrong Choice:n");
                                        break;
                }
        }
}
int isempty()
{
    if(start==NULL)
        return(1);
    else
        return(0);
}
void createSLL()
{
        struct node *temp=NULL;
        if(isempty()==1)
            start=temp;
}
void display()
{
        struct node *ptr;
        if(isempty()==1)
            printf("List is empty");
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d --> ",ptr->info );
                        ptr=ptr->next ;
                }
        }
        printf("\n");
}
void insertBegin(int val)
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=val;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insertAfter(int search,int element)
{
        struct node *ptr,*temp;
        ptr=(struct node *)malloc(sizeof(struct node));
        temp=(struct node *)malloc(sizeof(struct node));
        ptr=start;
        temp->info=element;
        temp->next =NULL;
        while(ptr!=NULL)
        {
            if(ptr->info==search)
            {
                temp->next=ptr->next;
                ptr->next=temp;
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL)
            printf("Position not found: ");
}
void deleteBefore(int element)
{
        struct node *ptr,*temp;
        ptr=(struct node *)malloc(sizeof(struct node));
        //temp=(struct node *)malloc(sizeof(struct node));
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->next->next->info==element)
            {
                temp=ptr->next->next;
                free(ptr->next);
                ptr->next=temp;
                printf("The node containing %d is deleted",element);
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL)
            printf("Position not found: ");
}

#include<stdio.h>
#define size 5
int arr[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value, int flag)
{
    int key = value % size;
    if(arr[key] == -1)
    {
        arr[key] = (value - flag);
        printf("%d inserted at arr[%d]\n", (value-flag),key);
        flag = 0;
    }
    else
    {
        printf("Collision occurred at arr[%d] : inserting %d at next position\n",key,arr[key]);
        flag++ ;
        insert(value+1, flag);
    }
}

void delete(int value)
{
    int pos = search(value);
    if(pos != -1)
        arr[pos] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

int search(int value)
{
    int i;
    for(i = 0; i < size; i++)
        if(arr[i] == value)
            return i;
    return -1;
}

void display()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

void main()
{
        int choice,val,count=0;
        while(1){

                printf("\n  MENU  \n");
                printf(" 1.Create     \n");
                printf(" 2.Insert     \n");
                printf(" 3.Display    \n");
                printf(" 4.Search     \n");
                printf(" 5.Delete     \n");
                printf(" 6.Exit       \n");
                printf("----------------------\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         init();
                                        printf("\nHash table of size %d is created",size);
                                        break;

                        case 2:         printf("\nEnter a value to insert:" );
                                        scanf("%d",&val);
                                        if(count != size)
                                        {
                                            count++;
                                            insert(val, 0);
                                        }
                                        else
                                            printf("\nHash table is full" );
                                        break;

                        case 3:         display();
                                        break;

                        case 4:         printf("Enter the value to be searched:" );
                                        scanf("%d",&val);
                                        if(search(val) != -1)
                                            printf("%d is at position %d ",val,search(val));
                                        else
                                            printf("%d not present in the hash table\n",val);
                                        break;

                        case 5:         printf("\nEnter a value to delete:" );
                                        scanf("%d",&val);
                                        if(count != 0)
                                        {
                                            count--;
                                            delete(val);
                                        }
                                        else
                                            printf("\nHash table is empty" );
                                        break;

                        case 6:         exit(0);
                                        break;

                        default:        printf("n Wrong Choice:n");
                                        break;
                }
        }
}

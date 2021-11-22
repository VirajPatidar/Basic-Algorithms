#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
}node;

node* createstack()
{
    struct Node *top = NULL;
    return top;
}

int isempty(node **top)
{
    if(*top == NULL)
        return 1;
    else
        return 0;
}

void push(int newinfo, node **top)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->info = newinfo;
    ptr->next = NULL;
    if(isempty(top) == 0)
        ptr->next = *top;
    *top = ptr;
}

void peek(node **top)
{
    if(isempty(top) == 1)
        printf("\nThe stack is empty :(");
    else
    {
        printf("\nFirst element: %d", (*top)->info);
    }
}

int pop(node **top)
{

    if(isempty(top) == 1)
    {
        printf("\nThe list is empty :(");
        return 0;
    }
    else
    {
        struct Node *temp;
        temp = *top;
        *top = (*top)->next;
        return temp->info;
        free(temp);
    }
}
void display(node **top)
{
        node *temp;
        temp = *top;
        if(isempty(top)==1)
            printf("Stack is empty");
        else
        {
                printf("The stack elements are:");
                while(temp!=NULL)
                {
                        printf("%d --> ",temp->info );
                        temp=temp->next ;
                }
        }
        printf("\n");
}
int main()
{
    int opt, new, index;
    node *Main_top;
    while(1)
    {
        printf("\n1. Create stack");
        printf("\n2. Insert a new element at the top");
        printf("\n3. Delete the top element");
        printf("\n4. Display the top element");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: Main_top = createstack();
                    break;

            case 2: printf("\nEnter the info: ");
                    scanf("%d", &new);
                    push(new, &Main_top);
                    break;

            case 3: if(isempty(&Main_top) == 1)
                    {
                        printf("\nThe list is empty :(");
                    }
                    else
                    {
                        index = pop(&Main_top);
                        printf("\nDeleted element: %d", index);
                    }
                    break;

            case 4: peek(&Main_top);
                    break;

            case 5: display(&Main_top);
                    break;

            case 6: return 0;

            default:printf("\nINVALID INPUT :(");
        }
    }
}

#include <stdio.h>
#define SIZE 5

typedef struct queue
{
    int data[SIZE];
    int rear, front, count;
}que;

que createQueue()
{
    que queue1;
    queue1.rear = -1;
    queue1.front = -1;
    queue1.count = 0;
    return queue1;
}
int isFull(que q1)
{
  if(q1.count == SIZE)
    return 1;
  //if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
  return 0;
}

int isEmpty(que q1)
{
  if(q1.count == 0)
    return 1;
  return 0;
}

void enQueue(int element, que *q)
{
  if(isFull(*q))
    printf("\n Queue is full!! \n");
  else
  {
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % SIZE;
    q->count++;
    q->data[q->rear] = element;
    printf("Inserted -> %d\n", element);
  }
}

int deQueue(que *q)
{
    int element;
    if (isEmpty(*q))
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = q->data[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->count++;
            q->front = (q->front + 1) % SIZE;
        }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display(que *q)
{
  int i = q->front;
  if (isEmpty(*q))
    printf(" \n Empty Queue\n");
  else
  {
    printf("\n Front -> %d ", q->front);
    printf("\n Items -> ");
    while(i<q->rear)
    {
        printf("%d ", q->data[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d ", q->data[i]);
    printf("\n Rear -> %d \n", q->rear);
  }
}

int main()
{
    int e, opt;
    que Main;
    while(1)
    {
        printf("\n1. Create Queue");
        printf("\n2. Insert an element");
        printf("\n3. Delete an element");
        printf("\n4. Display elements");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: Main = createQueue();
                    break;

            case 2: printf("Enter the element: ");
                    scanf("%d", &e);
                    enQueue(e, &Main);
                    break;

            case 3: deQueue(&Main);
                    break;

            case 4: display(&Main);
                    break;

            case 5: return 0;

            default:printf("\nINVALID INPUT :(");
        }
    }
}

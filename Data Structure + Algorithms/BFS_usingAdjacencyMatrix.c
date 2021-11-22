#include<stdio.h>
#define max 10

typedef struct queue {
    char arr[max];
    int front;
    int rear;
    int count;
}q;

int getIndex(char arr[], char ch) {
    int i;
    for(i=0; i<5; i++) {
        if(arr[i] == ch)
            return i;
    }
    return 0;
}

int isEmpty(q q1) {
    if(q1.count == 0)
        return 1;
    else
        return 0;
}

void enQueue(q *Q1, char data) {
    Q1->rear = (Q1->rear + 1) % max;
    Q1->arr[Q1->rear] = data;
    Q1->count = Q1->count + 1;
}

char deQueue(q *Q1) {
    char data = Q1->arr[Q1->front];
    Q1->front = (Q1->front + 1) % max;
    Q1->count = Q1->count - 1;
    return data;
}

void main() {
    int matrix[5][5];
    int visited[5];
    char vertex[5];
    int i, j;
    char data, ch = 'A';
    printf("Enter the matrix for A, B, C, D and E: ");
    for(i=0; i<5; i++) {
        vertex[i] = ch;
        visited[i] = 0;
        for(j=0; j<5; j++) {
            printf("%d.%d :", i, j);
            scanf("%d", &matrix[i][j]);
        }
        ch++;
    }
    printf("\nBreadth first traversal (starting from vertex C): ");
    q q1;
    q1.front = 0;
    q1.rear = -1;
    q1.count = 0;
    int curr = 2;
    visited[curr] = 1;
    enQueue(&q1, vertex[curr]);
    do {
        for(j=0; j<5; j++) {
            if(matrix[curr][j] == 1) {
                if(visited[j] == 0) {
                    enQueue(&q1, vertex[j]);
                    visited[j] = 1;
                }
            }
        }
        data = deQueue(&q1);
        curr = getIndex(vertex, q1.arr[q1.front]);
        printf("%c, ", data);
    }while(isEmpty(q1) == 0);
}

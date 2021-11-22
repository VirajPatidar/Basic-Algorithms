#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#define IN 99
#define N 6
void main()
{
    int i,j,w,ch,co,x,y;
    char source, target;
    int cost[N][N] = {  { 0, 4, 2, IN, IN, IN },
                        { 4, 0, 1, 5, IN, IN },
                        { 2, 1, 0, 8, 10, IN },
                        { IN, 5, 8, 0, 2, 6 },
                        { IN, IN, 10, 2, 0, 3 },
                        { IN, IN, IN, 6, 3, 0 }  };
    printf("The Adjacency Matrix is : \n\n");
    printf("   A   B   C   D    E    F \n");
    int c= 65;
    for(i=0;i< N;i++)
    {
        printf("%c |",c);
        for(j=0;j< N;j++)
            printf("%d | ",cost[i][j]);
        printf("\n");
        c++;
    }
    printf("\nEnter the source: ");
    scanf("%c", &source);
    int src = (int)source - 65;
    printf("Enter the target: ");
    scanf(" %c", &target);
    int tar = (int)target - 65;
    co = dijsktra(cost,src,tar);
    printf("\nThe total cost of the path is : %d\n",co);
}
int dijsktra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=0;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=0;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    printf("\nThe shortest path is : ");
    printf("%s", path);
    return dist[target];
}

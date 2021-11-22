#include <iostream>
using namespace std;

#define nV 4
#define INF 999

void printMatrix(int matrix[][nV]);

void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
    printMatrix(matrix); cout<<"\n";
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
    int graph[nV][nV];
    cout<<"Enter the values of 4 X 4 adjacency matrix\n";
    
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++)
            cin>>graph[i][j];
    }
    
    floydWarshall(graph);

}

//   int graph[nV][nV] = {{0, 3, INF, 7},
//                        {8, 0, 2, INF},
//                        {5, INF, 0, 1},
//                        {2, INF, INF, 0}};
  
//   int graph[nV][nV] = {{0, 3, INF, 5},
//                        {2, 0, INF, 4},
//                        {INF, 1, 0, INF},
//                        {INF, INF, 2, 0}};
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high) {
  int pivot = array[low];
  int i = low;
  int j = high;
  while(i<j){
      while(array[i]<=pivot )
            i++;
            
     while(array[j] > pivot)
        j--;
      
      if(i<j)
        swap(&array[i], &array[j]);
  }
  swap(&array[j], &array[low]);
  return (j);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main() {
  int data[] = {4, 3, 5, 8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}


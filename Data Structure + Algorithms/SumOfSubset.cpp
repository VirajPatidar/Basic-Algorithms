#include <bits/stdc++.h>
using namespace std;
static int nodes;

void printValues(int arr[], int size){
   for (int i = 0; i < size; i++) {
      cout<<arr[i]<<" ";
   }
   cout<<"\n";
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
   nodes++;
   if (target_sum == sum) {
      printValues(t, t_size);
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      return;
   }
   else {
      for (int i = ite; i < s_size; i++) {
         t[t_size] = s[i];
         subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}

void generateSubsets(int s[], int size, int target_sum){
   int* tuplet_vector = (int*)malloc(size * sizeof(int));
   subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
   free(tuplet_vector);
}

int main(){
   int set[] = { 5, 10, 12, 13, 15, 18 };
   int size = sizeof(set) / sizeof(set[0]);
   int sum = 0;
   cout<<"Enter the sum: ";
   cin>>sum;
   cout<<"The subsets are: \n";
   generateSubsets(set, size, sum);
   cout<<"\nTotal Nodes generated :"<<nodes<<"\n";
   return 0;
}
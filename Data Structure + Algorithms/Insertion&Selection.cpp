#include <bits/stdc++.h> 
using namespace std; 

void insertionSort(int arr[], int n) 
{ 
	int i, key, j, c1=0, c2=0; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1;
		c1++; 
		while (j >= 0 && arr[j] > key) 
		{ 
			c2++;
			arr[j + 1] = arr[j];
			j-- ; 
		} 
		arr[j + 1] = key; 
	}
	cout<<"Number of operations: "<<(c2)<<"\n"; 
}

void selectionSort(int arr[], int n) 
{ 
	int i, j, min, temp, c3=0; 
	for (i = 0; i<n-1; i++) 
	{ 
		min = i; 
		for (j=i+1; j<n; j++){
			c3++;
		    if (arr[j] < arr[min]) 
			    min = j; 
		} 
		temp = arr[i];
		arr[i]= arr[min];
		arr[min] = temp;
	}
	cout<<"Number of operations: "<<c3<<"\n"; 
}

void print(string s, int arr[], int n) 
{ 
	int i;
	cout<<s+" : ";
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() 
{
	cout<<"Worst Case\n"; 
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, n);
	print("InsertionSort",arr, n);
	int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; cout<<"\n";
	selectionSort(arr2, n);
	print("selectionSort",arr2, n); 
	return 0; 
}
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

void swap(int arr[], int a, int b){
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void waveSort(int arr[], int n){
	
	for (int j = 1; j < n; j += 2){
		
		if (arr[j] > arr[j - 1])
			swap(arr, j, j - 1);

		if ((arr[j] > arr[j + 1]) and (j <= n - 2))
			swap(arr, j, j + 1);
	}
}

int main(int argc, char *argv[]){
	
	int n;
	cin >> n;
	int arr[n];

	for (int I = 0; I < n; I++)
		cin >> arr[I];

	waveSort(arr, n);

	for (int I = 0; I < n; I++)
		cout << arr[I] << " ";

	return 0;
}
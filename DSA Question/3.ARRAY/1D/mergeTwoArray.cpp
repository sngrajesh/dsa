#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{
	int n, m;
	int *ptr1, *ptr2;
	printf("ENTER : ");
	scanf("%d", &n);
	printf("ENTER : ");
	scanf("%d", &m);
	ptr1 = (int*)calloc(n, sizeof(int)); 
	if (ptr1 == NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}

	ptr2 = (int*)calloc(m, sizeof(int)); 
	if (ptr2 == NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	printf("Array 1\n");
	for (int i = 0; i < n; ++i)
	{
		cout <<">>";
		cin >> ptr1[i];
	}
	printf("Array 2\n");
	for (int i = 0; i < m; ++i)
	{
		cout <<">>";
		cin >> ptr2[i];
	}
	
	ptr1 = (int*)realloc(ptr1, n * sizeof(int)); 
	for (int i = 0; i < m; ++i)
	{
		ptr1[n+i]= ptr2[i];
	}
	
	free(ptr2); 
	
	for (int i = 0; i <( m+n); ++i)
	{
		cout<<  ptr1[i] <<" ";
	}
	
	
	return 0;
}
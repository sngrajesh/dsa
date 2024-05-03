#include <iostream>
#include <vector>
using namespace std;
int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}

void commonElements(int n1, int A[], int n2, int B[], int n3, int C[])
{
	int m=max(A[n1-1],B[n2-1]);
	m= max(m,C[n3-1]);
	int v[m];
	for (int a = 0; a < n1; a++)
	{
		v[A[a]] += 1;
		if (v[A[a]] == 3)
			cout << A[a] << endl;
	}

	for (int a = 0; a < n2; a++)
	{
		v[B[a]] += 1;
		if (v[B[a]] == 3)
			cout << B[a] << endl;
	}

	for (int a = 0; a < n3; a++)
	{
		v[C[a]] += 1;
		if (v[C[a]] == 3)
			cout << C[a] << endl;
	}
}

void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2 && k < n3)
	{
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
		{
			cout << ar1[i] << " ";
			i++;
			j++;
			k++;
		}
		else if (ar1[i] < ar2[j])
			i++;
		else if (ar2[j] < ar3[k])
			j++;	
		else
			k++;
	}
}
int main(int argc, char *argv[])
{
	
	int n1=6;
	int A[] = {1, 5, 10, 20, 40, 80};
	int n2 = 5;
	int B[] = {6, 7, 20, 80, 100};
	int n3 = 8;
	int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
	/*
	int n1;
	printf("ENTER N1 : ");
	scanf("%d", &n1);
	int A[n1];
	for (int j = 0; j < n1; j++)
	{
		printf("%d>>", j + 1);
		cin >> A[j];
	}
	
	int n2;
	printf("ENTER N2 : ");
	scanf("%d", &n2);
	int B[n2];
	for (int j = 0; j < n2; j++)
	{
		printf("%d>>", j + 1);
		cin >> B[j];
	}
	
	int n3;
	printf("ENTER N3 : ");
	scanf("%d", &n3);
	int C[n3];
	for (int j = 0; j < n3; j++)
	{
		printf("%d>>", j + 1);
		cin >> C[j];
	}
	*/
	commonElements(n1, A, n2, B, n3, C);	
	findCommon(A,B,C,n1,n2,n3);
	return 0;
}
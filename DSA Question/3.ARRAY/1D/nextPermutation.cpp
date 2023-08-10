#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void nextPermutation1(std::vector<int> &a)
{
	int n= a.size();
	if (n == 0)
		return;
	int t = -1;
	for (int j = n - 1; j > 0; j--)
	{
		if (a[j] > a[j - 1])
		{
			t = j;
			break;
		}
	}
	if (t == -1)
		reverse(a.begin(), a.end());
	else
	{
		int p = t;
		for (int k = t + 1; k < n; k++)
		{
			if (a[k] > a[t - 1] and a[k] <= a[p])
				p = k;
		}
		std::swap(a[t - 1], a[p]);
		reverse(a.begin() + t, a.end());
	}

}
	

void nextPermutation2(vector<int> &A) {
    int i,small,big,temp;
    int j=0;
    for(i=A.size()-1;i>0;i--)
    {
        if(A[i]>A[i-1])
            break;
    }
    if(i==0)
    {
        sort(A.begin(),A.end());
        return ;
    }
    small=i-1;
    big=i;
    temp=big;
    for(i=A.size()-1;i>big;i--)
    {
        if(A[i]>A[small] && A[i]<A[temp])
            temp=i;
    }
    int t=A[temp];
    A[temp]=A[small];
    A[small]=t;
    small++;
    sort(A.begin()+small,A.end());     
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &j : a)
		std::cin >> j;

	nextPermutation1(a);
	 for (int k = 0; k < a.size(); k++)
		cout << a[k];
	return 0;
}
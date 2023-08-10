#include <iostream>
using namespace std;

int main()
{
    //Full Pyramid
	int n ;
    cin >> n;
	int k =  n ;

	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k; j++)
			cout << " ";
        k = k - 1;

		for (int j = 0; j <= i; j++) {
			cout << "* ";
		}

		cout << endl;
	}
	return 0;
}

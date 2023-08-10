#include <iostream>
using namespace std;

int main()
{
    //Hollow Full Pyramid
	int n ;
    cin >> n;
	int k =  n ;

	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k; j++)
			cout << " ";
        k = k - 1;

		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i || i==(n-1))
                cout << "* ";
            else
                cout << "  ";
		}

		cout << endl;
	}
	return 0;
}

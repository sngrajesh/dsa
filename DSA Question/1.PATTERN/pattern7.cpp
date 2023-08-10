#include <iostream>
using namespace std;

int main()
{
    //Inverted full pyramid
	int n ;
    cin >> n;
	int k =  n ;

	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < (n - k); j++)
			cout << " ";
        k = k - 1;

		for (int j = 0; j < (n- i); j++) {
			cout << "* ";
		}

		cout << endl;
	}
	return 0;
}


#include <iostream>
#include <math.h>
using namespace std;

void decToBinary1(unsigned int n)
{
	int binaryNum[32];

	int i = 0;
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}
void decToBinary2( unsigned int n)
{
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

void decToBinaryNegative1( unsigned int n)
{
    int number_of_bits = floor(log2(n))+1;
    int onceComplement = ((1 << number_of_bits) - 1) ^ n;

    for (int i = 31; i >= 0; i--) {
        int k = onceComplement >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

void decToBinaryNegative2( unsigned int n)
{
    unsigned long long int i = 0 , ans  = 0;
    if(n < 0 ){
        n = pow(2 , 16 ) + n;
    }   
    cout << n << endl;
   
    
        for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }  
    

}

int main()
{
	unsigned int n ; cin >> n;
	decToBinaryNegative2(n);
	return 0;
}

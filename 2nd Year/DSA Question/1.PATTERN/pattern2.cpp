#include<iostream>
using namespace std;

int main()
{
	//Hollow Reactangle
	int i, j, rows, columns;
	char ch = '*';

	cin >> rows;
	cin >> columns;

	for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= columns; j++)
		{
			if(i == 1 || i == rows || j == 1 || j == columns)
			{
				cout << ch;
			}
			else
			{
				cout << " ";
			}          
        }
        cout << "\n";
    }
 	return 0;
}
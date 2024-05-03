#include <iostream>
// C++ program to find maximum possible profit with at most two transactions

using namespace std;

// Returns maximum profit with two transactions on a given list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
	// Create profit array and initialize it as 0
	int* profit = new int[n];
	for (int i = 0; i < n; i++)
		profit[i] = 0;

	/*Get the maximum profit with only one transaction allowed. After this loop profit[i] contains maximum profit from price[i..n-1] using at most one trans. */
	int max_price = price[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		// max_price has maximum  of price[i..n-1]
		if (price[i] > max_price)
			max_price = price[i];

		/* we can get profit[i] by taking maximum of:
		a) previous maximum, i.e., profit[i+1]
	    b) profit by buying at price[i] and selling at max_price
		*/
		profit[i]
			= max(profit[i + 1], max_price - price[i]);
	}

	/* Get the maximum profit with two transactions allowed After this loop, profit[n-1] contains the result */
	int min_price = price[0];
	for (int i = 1; i < n; i++) {
		// min_price is minimum price in price[0..i]
		if (price[i] < min_price)
			min_price = price[i];

		/* Maximum profit is maximum of:
		 a) previous maximum, i.e., profit[i-1]
		 b) (Buy, Sell) at (min_price, price[i]) and add
		 profit of other trans. stored in profit[i]
		*/
		profit[i] = max(profit[i - 1],
						profit[i] + (price[i] - min_price));
	}
	int result = profit[n - 1];

	delete[] profit; // To avoid memory leak

	return result;
}



int getMax(int price[], int n){
	// adding array
	int profit = 0;

	// Initializing variable 
	/*valley-peak approach

						            	80
						            	/
			 	30	        	 /
     			/ \	      	 25
	   		/   15      	 /
 			/    	 \   	 /
		   /      	   10  /
		 /	      		\ /
	   /	         		8
	 /  
    2	   
	   
	*/
	for (int i = 1; i < n; i++)
	{	
	//traversing through array from (i+1)th position
		int sub = price[i] - price[i - 1];
		if (sub > 0)
			profit += sub;
	}
	return profit; 
}
	
int main()
{
	int n =0;
	
	int price1[] = {10, 22, 5, 75, 65, 80};
	n = sizeof(price1)/sizeof (price1[0]);
	//Output:  87
	cout << "Maximum Profit=" << maxProfit(price1,n) <<endl;
	cout << "Maximum Profit=" << getMax(price1,n) <<endl;
	


	int price2[] = {2, 30, 15, 10, 8, 25, 80};
	n = sizeof(price2)/sizeof (price2[0]);
	//Output:  100
	cout << "Maximum Profit=" << maxProfit(price2,n) <<endl;
	cout << "Maximum Profit=" << getMax(price2,n) <<endl;


	int price3[] = {100, 30, 15, 10, 8, 25, 80};
	n = sizeof(price3)/sizeof (price3[0]);
	//Output:  72
	cout << "Maximum Profit=" << maxProfit(price3,n) <<endl;
	cout << "Maximum Profit=" << getMax(price3,n) <<endl;


	int price4[] = {90, 80, 70, 60, 50};
	n = sizeof(price4)/sizeof (price4[0]);
	//Output:  0
	cout << "Maximum Profit=" << maxProfit(price4,n) <<endl;
	cout << "Maximum Profit=" << getMax(price4,n) <<endl;
		
	return 0;
}


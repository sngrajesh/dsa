void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}


/********************************Rajesh*******************************/
// #include <bits/stdc++.h>
// void insterInSortedOrder(stack<int> &stack, int data) {
//   if (stack.empty()) {
//     stack.push(data);
//     return;
//   }

//   int topData = stack.top();
//   if (topData > data) {
//     stack.pop();
//     insterInSortedOrder(stack, data);
//     stack.push(topData);
//   } else {
//     stack.push(data);
//   }
// }

// void sortStack(stack<int> &stack) {
//   if (stack.empty())
//     return;
//   int data = stack.top();
//   stack.pop();
//   sortStack(stack);
//   insterInSortedOrder(stack, data);
// }
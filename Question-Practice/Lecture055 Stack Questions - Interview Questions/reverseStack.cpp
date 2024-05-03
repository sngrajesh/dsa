
void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}


/**************************Rajesh****************************/
// stack<int> pushAtBottom(stack<int> &myStack, int x) {
//   if (myStack.empty()) {
//     myStack.push(x);
//   } else {
//     int topData = myStack.top();
//     myStack.pop();
//     pushAtBottom(myStack, x);
//     myStack.push(topData);
//   }
//     return myStack;
// }



// void reverseStack(stack<int> &stack) {
//     if(stack.empty()){
//         return;
//     }
//     int data = stack.top();
//     stack.pop();
//     reverseStack(stack);
//     pushAtBottom(stack, data);
// }
void solve(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    solve(s, x);
    
    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}


/*********************Rajesh**************************/
// #include <bits/stdc++.h>
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


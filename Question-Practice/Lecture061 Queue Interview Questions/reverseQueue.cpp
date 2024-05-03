queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}


/********************Rajesh***********************/
// queue<int> rev(queue<int> q)
// {
//     if (!q.empty()) {
//         int data = q.front();
//         q.pop();
//         q = rev(q); // Store the result of the recursive call
//         q.push(data);
//     }
//     return q;
// }

//Question : queue using stack first then used this queue(queuestack) 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void pushToSQueue(stack<int>&s,int n){
    stack<int>vessel;
    if(s.empty()){
        s.push(n);
        return;
    }
    while(!s.empty()){
        vessel.push(s.top());
        s.pop();
    }
    s.push(n);
    while(!vessel.empty()){
        s.push(vessel.top());
        vessel.pop();
    }
}
void solve(queue<int> &q1){
    //
    stack<int>q2;
    int n=q1.size();
    n=n/2;
    //aaadhe element daldo q2 me
    while(n){
        pushToSQueue(q2,q1.front());
        q1.pop();
        n--;
    }
    // jab tak q2 empty nai tab tak q1 me element dalo aur pop q2 ke element dalo aur pop
    while(!q2.empty()){
        q1.push(q2.top());
        q1.push(q1.front());
        q1.pop();
        q2.pop();
    }
}
void printq(queue<int>q){
    while(!q.empty()){
        cout<<"\n->"<<q.front();
        q.pop();
    }
}
int main() {
    queue<int>v;
    // 11 12 13 14 15 16 17 18 19 20
    v.push(11);
    v.push(12);
    v.push(13);
    v.push(14);
    v.push(15);
    v.push(16);
    v.push(17);
    v.push(18);
    v.push(19);
    v.push(20);
    solve(v);
    printq(v);
    return 0;
} 
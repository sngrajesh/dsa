#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int e){
	
	if(!s.empty ()){
		s.push(e);
		return;
	}
	
	int t = s.top();
	s.pop();
	insertAtBottom(s,e);
	s.push(t);
		
}


void reverseStack(stack<int> &s){
	
	if(!s.empty())
		return ;
		
	int e = s.top();
	s.pop();	
	reverseStack(s);	
	insertAtBottom(s,e);
}


int main(int argc, char *argv[])
{
	stack<int>a1;
	int arr1[] = {11, 1, 13, 21, 3, 7};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	for(int I=0 ; I<m ; I++)
		a1.push(arr1[I]);
	reverseStack(a1);
	while(!a1.empty()){
		cout<<a1.top()<<" ";
		a1.pop();
	}cout<<endl;
	
	stack<int>a2;
	int arr2[] = {11, 3, 7, 1};
	int n = sizeof(arr2) / sizeof(arr2[0]);
	for(int I=0 ; I<n ; I++)
		a2.push(arr2[I]);
	reverseStack(a2);	
	while(!a2.empty()){
		cout<<a2.top()<<" ";
		a2.pop();
	}cout<<endl;	
	
	return 0;
}
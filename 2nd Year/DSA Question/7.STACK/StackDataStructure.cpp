#include<iostream>
#define n 10

using namespace std;

class stack{
	
	int *arr;
	int topIndex;	
	public:
		
	stack(){
		arr = new int[n];
		topIndex = -1;
	}
	
	void push(int a){				
		if(topIndex == (n-1)){
			cout<<"Stack Overflowed\n";
			return ;
		}
		topIndex++;		
		arr[topIndex] = a;	
		cout<<a<<" is added\n";
		
	}
	
	void pop(){		
		if(topIndex == (-1)){
			cout<<"No element in Stack\n";
			return ;
		}
		cout<<arr[topIndex]<<" is removed\n";
		topIndex--;		
	}
	
	int top(){		
		if(topIndex == -1){
			cout <<"No element in Stack\n";
			return -1;
		}
	return arr[topIndex];
	}
	
	bool empty(){
		return topIndex==-1;
			/*return 1;
		return 0;*/
	}
	
};


int main(int argc, char *argv[])
{
	stack s;
	s.push(1);
	s.push(2);
	cout<<"Is empty or not : ";
	cout<<s.empty()<<endl;
	s.push(3);
	cout<<"Current top element : ";
	cout<<s.top()<<endl;
	s.pop();
	cout<<"Current top element : ";
	cout<<s.top()<<endl;
	s.pop();
	cout<<"Current top element : ";
	cout<<s.top()<<endl;
	s.pop();
	cout<<"Is empty or not : ";
	cout<<s.empty()<<endl;
	s.pop();
	cout<<"Is empty or not : ";
	cout<<s.empty()<<endl;
	
	return 0;
}
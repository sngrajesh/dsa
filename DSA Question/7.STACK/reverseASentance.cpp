#include <iostream>
#include <stack>
using namespace std;

void reverseAString1(string s){
	
	stack<string>r;
	string m= " ";
	for(int I= 0 ;I<s.length() ; I++){
		if(s[I]==' '){
			r.push(m);
			m="";
		}
		m+=s[I];
	}
	
	while(!r.empty()){
		cout<<r.top();
		r.pop();
	}cout<<endl;
}


void reverseAString2(string s){
	
	stack<string>r;
	for(int I= 0 ;I<s.length() ; I++){
		string m= " ";
		while(s[I]!=' ' and I<s.length()){
			m+=s[I];
			I++;
		}
		r.push(m);		
	}
	
	while(!r.empty()){
		cout<<r.top();
		r.pop();
	}cout<<endl;
}



int main(int argc, char *argv[])
{
	string s = "hello, how are you ? ";
	cout<<s<<endl;
	reverseAString1(s);
	reverseAString2(s);
	
	return 0;
}
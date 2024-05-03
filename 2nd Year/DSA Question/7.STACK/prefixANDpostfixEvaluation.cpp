#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEvaluation(string e){
	
	stack<int>s;
	for(int I=e.length()-1 ; I>=0 ; I--){
		if(e[I]>='0' and e[I]<'9'){
			s.push(e[I]-'0');
		}
		else{
			int operator1 = s.top();
			s.pop();
			int operator2 = s.top();
			s.pop();			
			switch (e[I]){
				case '+':
					s.push(operator1+operator2);
					break;
				case '-':
					s.push(operator1-operator2);
					break;
				case '*':
					s.push(operator1*operator2);
					break;
				case '/':
					s.push(operator1/operator2);
					break;
				case '^':
					s.push(pow(operator1,operator2));
					break;
			}
		}
	}
	
	return s.top();
}

int postfixEvaluation(string e){
	
	stack<int>s;
	for(int I=0 ; I<e.length() ; I++){
		if(e[I]>='0' and e[I]<'9'){
			s.push(e[I]-'0');
		}
		else{
			int operator2 = s.top();
			s.pop();
			int operator1 = s.top();
			s.pop();			
			switch (e[I]){
				case '+':
					s.push(operator1+operator2);
					break;
				case '-':
					s.push(operator1-operator2);
					break;
				case '*':
					s.push(operator1*operator2);
					break;
				case '/':
					s.push(operator1/operator2);
					break;
				case '^':
					s.push(pow(operator1,operator2));
					break;
			}
		}
	}
	
	return s.top();
}
	
		
			
					
int main(int argc, char *argv[])
{
	
	cout<<prefixEvaluation("-+7*45+20")<<endl;
	cout<<postfixEvaluation("46+2/5*7+")<<endl;
	
	return 0;
}







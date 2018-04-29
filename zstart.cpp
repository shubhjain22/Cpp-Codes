#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
char stack[100] , ind ;

char top(){
	return stack[ind];
}
void push(char c){
	++ind;
	stack[ind] = c;
}
void pop(){
	stack[ind] = 0;
	--ind;
}
bool isEmpty(){
	if(stack[ind]==0){
		return true;
	}
	else{
		return false;
	}
}
int main(void){
	ind=0;
	cout << "Enter the paranthesis" << endl;
	string str;
	cin >> str ;
	for(int i=0;i<str.size();i++){
		if(str[i] == '{' || str[i] == '(' || str[i]=='['){
			push(str[i]);
		}
		else if(str[i]=='}'){
			char ch = top();
			if(ch=='{'){
				pop();
			}
			else{
				break;
			}
		}
		else if(str[i]==')'){
			char ch = top();
			if(ch == '('){
				pop();
			}
			else{
				break;
			}
		}
		else if(str[i]==']'){
            char ch = top();
            if(ch=='['){
                pop();
            }
            else{
                break;
            }
        }
	}
	if(isEmpty()==true){
		cout << "Balanced " << endl;
	}
	else{
		cout << "Not Balanced" << endl;
	}
}
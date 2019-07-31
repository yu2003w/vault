#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	char expr[1000];
	char stack[100];
	int top = 0, i = 0;
	cin>>expr;
	for (int i=0; expr[i] != '\0'; i++) {
		if (expr[i] == '{' || expr[i] == '[' || expr[i] == '(') {
			if (top == 100) {
				cout<<"stack overflowed"<<endl;
				break;
			}
			stack[top++] = expr[i];
		} 
		if (expr[i] == ')') {
			if (top >= 1 && stack[top-1] == '(') {
				top--;
			} else 
			    break;
		}
		if (expr[i] == ']') {
			if (top >= 1 && stack[top-1] == '[') {
				top--;
			} else 
			    break;
		}
		if (expr[i] == '}') {
			if (top >= 1 && stack[top-1] == '{') {
				top--;
			} else 
			    break;
		}
	}
	if (top == 0) {
		cout<<"validated"<<endl;
	} else
	    cout<<"invalid"<<endl;
}

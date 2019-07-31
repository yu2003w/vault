#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	float a, b, ret;
	char op;
	cin>>a>>b>>op;
	switch(op) {
		//case '+':
		case 43:
			ret = a+b;
			break;
		case '-':
			ret = a-b;
		    break;
		case '*':
		    ret = a*b;
		    break;
		case '/':
			if (b == 0) {
				cout<<"Divided by zero"<<endl;
				return 0;
			}
			ret = a/b;
			break;
		case '%':
			ret = (int)a%(int)b;
			break;
		case 'B':
			ret = (a+b)*b;
			break;
		default:
			cout<<"Invalid Operator"<<endl;
	}
	cout<<"result is "<<ret<<endl;
}

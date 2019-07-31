#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	float c;
	cin>>a>>b;
	if (a < 1 || a > 100) {
		cout<<"Please input number between 1 and 100"<<endl;
		return 0;
	}
	if (a%2 == 0) {
		cout<<a<<" is even number"<<endl;
	} else {
		cout<<a<<" is odd number"<<endl;
	} 
	
	if (b != 0) 
		if (a > b)
		    c = (float)a/b;
		else
		    c = (float)b/a;
	else
	    cout<<"b is 0"<<endl;
	cout<<c<<" is "<<c<<endl;
}

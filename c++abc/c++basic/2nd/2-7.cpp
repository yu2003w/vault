#include<iostream>
using namespace std;

int main(int argc, char**argv) {
	int i, a, b, c;
	cin>>i;
	if (i > 999) {
		cout<<"invalid number"<<endl;
		return -1;
	}
	else if (i < 0) {
		cout<<"negative number"<<endl;
		return -1;
	}
	else 
	   cout<<"input number is"<<i<<endl;
	a = i%10;
	b = (i/10)%10;
	c = i/100;
	i = a*100 + b*10 + c;
	cout<<i<<endl; 
}

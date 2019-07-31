#include <iostream>
using namespace std;

int func1(int a) {
	return a;
}

int sum(int a, int b) {
	return a+b;
}
typedef int (*Sf)(int, int);

int main(int argc, char** argv) {
	int (*p)(int);
	p=func1;
	cout<<p(5)<<" "<<(*p)(10)<<endl;
	Sf func2 = sum;
	cout<<func2(5,10)<<" "<<(*func2)(10,20)<<endl;
}

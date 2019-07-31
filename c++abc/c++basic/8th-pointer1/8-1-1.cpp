#include <iostream> 
using namespace std;
int main(int argc, char** argv) {
	int a, *pa=NULL, b;
	cout<<"a="<<a<<", &a="<<&a<<endl;
	pa = &a;
	cout<<"*pa="<<*pa<<", pa="<<pa<<endl;
	a=4;
	cout<<"*pa="<<*pa<<", pa="<<pa<<endl;
	*pa=6;
	cout<<"*pa="<<*pa<<", pa="<<pa<<", a="<<a<<endl;
    cout<<"&pa="<<&pa<<endl;
}

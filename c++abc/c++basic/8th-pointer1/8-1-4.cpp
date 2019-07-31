#include <iostream>
using namespace std;

int main(int argc, char**argv) {
	int a = 10;
	double b = 11.25;
	void *p;
	p = &a;
	cout<<*(int*)p<<endl;
	p = &b;
	cout<<*(double*)p<<endl;
	int **p1 = NULL;
	int *p2 = &a;
	p1 = &p2;
	cout<<*p2<<" "<<**p1<<endl;
}

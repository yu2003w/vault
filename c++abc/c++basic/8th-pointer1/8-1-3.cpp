#include <iostream>
using namespace std;
int swap(int *, int *);
int main(int argc, char** argv) {
	int a=3, b=4;
	cout<<a<<" "<<b<<endl;
	swap(&a, &b);
	cout<<a<<" "<<b<<endl;
	int *pa = &a, *pb = &b;
	swap(pa, pb);
	cout<<a<<" "<<b<<endl;
}

int swap(int *p1, int *p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp; 
}

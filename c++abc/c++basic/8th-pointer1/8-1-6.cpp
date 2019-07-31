#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int *a = new int[10];
	for (int i=0; i<10; i++) {
		cin>>a[i];
	}
	for (int i=2; i<10; i++) {
		a[i] += a[i-1];
	}
	for (int i=0; i<10; i++) {
		cout<<a[i]<<" "; 
	}
	delete []a;
} 

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<i; j++) {
			cout<<"*";
		}
		cout<<endl;
	}
	
}

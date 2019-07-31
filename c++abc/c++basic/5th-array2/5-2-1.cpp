#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int data[10];
	int n = 10;
	for (int i = 0; i < 10; i++) {
		cin>>data[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (data[j] < data[j+1]) {
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	    cout<<data[i] <<" ";
	cout<<endl;
	
}

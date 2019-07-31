#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int data[10];
	
	for (int i = 0; i < 10; i++) {
		cin>>data[i];
	}
	
	// 如何判断是否排序已经完成 
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (data[i] < data[j]) {
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	    cout<<data[i] <<" ";
	cout<<endl;
	
}

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int data[10] = {21, 35, 46, 72, 18, 31, 45, 77, 29, 82};
	
	int *p = data;
	cout<<data[0]<<" "<<*p<<endl;
	for (int i = 0; i < 10; i++) {
		cout<<*(p+i)<<" "; 
	}
	cout<<endl;
	for (int i = 0; i < 10; i++) {
		cout<<p[i]<<" "; 
	}
	cout<<endl;
	for (int i = 0; i < 10; i++) {
		cout<<*(p++)<<" "; 
	}
	cout<<endl;
	p = &data[9];
	for (int i = 0; i < 10; i++) {
		cout<<*(p--)<<" "; 
	}
	cout<<endl;
	//补充程序，将数组下标是偶数的元素输出 
}

#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	
	int sum = 0;
	int a = 0, b =5;
	a = b++;
	cout<<a<<endl;
	//¼ÆËã 1! + 2! + ... + 10! 
	for (int i = 1; i <= 10; i++) {
		int ret = 1;
		for (int j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;
	}
	
	cout<<"sum="<<sum<<endl;
	
	// ¼ÆËã 1£¡ + 2£¡ + ... + 15! 
}

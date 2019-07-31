#include <iostream>
using namespace std;

int js(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int ret = 1;
		for (int j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;
	}
	return sum;
}

int main(int argc, char ** argv) {
	
	//¼ÆËã 1! + 2! + ... + 10! 
	cout<<"1!+...+10!="<<js(10)<<endl;
	// ¼ÆËã 1£¡ + 2£¡ + ... + 15! 
	cout<<"1!+...+15!="<<js(15)<<endl;
	
	int v25 = js(25);
	cout<<"1!+...+25!="<<v25<<endl;

}

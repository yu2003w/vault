#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a[5] = {78,96};
	a[2] = 54, a[3] = 29, a[4] = 23;
	for (int i=0; i< 5; i++) {
		cout<<"a["<<i<<"]="<<a[i]<<"," ;
	}
	cout<<endl;
	//利用循环结构来对数组a的元素重新赋值，
	// 每个值为a[0] + i*5, 并且将各元素值逆序输出 
	 
}

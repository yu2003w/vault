#include <iostream>
using namespace std;
/*
给定一个整型数组，给定一个数值m，如果数组中任意几个元素之和等于m，输出组合数之和
*/
const int LEN = 5;
//int data[10] = {14, 24, -5, 3, 9, 101, 72, 39, 41, 27};
int data[5] = {2, 7, 6, -3, 3};
int fn(int n, int m);
int main(int argc, char** argv) {
	int value;
	cin>>value;
	cout<<fn(5, value)<<endl;
}

/*
？？如何输出可能的运算组合 
*/ 
int fn(int n, int m) {	
	if (n == 1) {	
		if (data[LEN-n] == m) {
			cout<<"data["<<LEN-n<<"]="<<data[LEN-n]<<" f("<<n<<","<<m<<") = "
			<<1<<endl;
			return 1;
		} else {
			cout<<"data["<<LEN-n<<"]="<<data[LEN-n]<<" f("<<n<<","<<m<<") = "
			<<0<<endl;
			return 0;
		}
	} else {
		cout<<"data["<<LEN-n<<"]="<<data[LEN-n];
		int ret;
		if (data[LEN-n] == m) {
			cout<<" f("<<n<<","<<m<<") = "<<"1 + f("<<n-1<<","<<m<<")"<<"+ f("
			<<n-1<<","<<m-data[LEN-n]<<")"<<endl;
			ret = 1 + fn(n-1, m) + fn(n-1, 0);
	    } else {
			cout<<" f("<<n<<","<<m<<") = "<<"f("<<n-1<<","<<m<<")"<<"+ f("
			<<n-1<<","<<m-data[LEN-n]<<")"<<endl;
			ret = fn(n-1, m) + fn(n-1, m-data[LEN-n]);
		}
		
		cout<<"f("<<n<<","<<m<<") = "<<ret<<endl;
		return ret;
	}

}


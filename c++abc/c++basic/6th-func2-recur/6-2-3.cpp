#include <iostream>
using namespace std;
/*
给定一个整型数组，给定一个数值m，如果数组中任意几个元素之和等于m，则输出yes, 否则输出No 
*/
const int MAX = 10;
int data[10] = {14, 24, -5, 3, 9, 101, 72, 39, 41, 27};
bool check(int n, int m);
int main(int argc, char** argv) {
	int m = 0;
	cin>>m;
	if (check(9, m)) {
		cout<<endl<<"Yes";
	}
	else cout<<"No"<<endl;
}

/*
？？如何输出可能的运算组合 
*/ 
bool check(int n, int m) {
	if (data[n] == m) {
		cout<<data[n]<<" ";
		return true;
	}
	else if (n == 0) return false;
	else {
		if (check(n-1, m-data[n])) {
			cout<<data[n]<<" ";
			return true;
		}
		if (check(n-1, m))
		    return true;
		//return (check(n-1, m-data[n]) || check(n-1, m));
	}
}

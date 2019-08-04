#include <iostream> 
using namespace std;
/*
输出斐波那契数列
f(n) = f(n-1)+f(n-2) n > 2
f(1) = 1 
f(2) = 1 
*/
int fib(int n) { 
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fib(n-1) + fib(n-2);
	}
	
}
int main(int argc, char** argv) {
	int n = 0;
	cin>>n;
	for (int i = 1; i <=n; i++)
	    cout<<fib(i)<<" ";
	cout<<endl<<fib(n);
}


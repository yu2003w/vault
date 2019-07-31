#include <iostream>
using namespace std;
/*
Ackmann函数值的计算,其中m,n是非负整数, 且m<=3, n<=10 
akm(m,n) = n + 1             m = 0
akm(m,n) = akm(m-1, 1)       m > 0, n = 0
akm(m,n) = akm(m-1, akm(m,n-1)    m > 0, n > 0 
*/
int akm(int m, int n) {
	if (m == 0) return (n+1);
	else if (n == 0) return akm(m-1, 1);
	else return akm(m-1, akm(m, n-1));
}
int main(int argc, char**argv) {
	cout<<"akm(0, 2)="<<akm(0,2)<<endl;
	cout<<"akm(3, 0)="<<akm(3, 0)<<endl;
	int m, n;
	cin>>m>>n;
	cout<<"akm("<<m<<","<<n<<")="<<akm(m,n);
	
	for (int i = 0; i <= 10; i++) {
		cout<<"loop started for "<<i<<endl;
		if (i % 3 == 0)
		    continue;
		cout<<"loop ended for "<<i<<endl;
	}
}

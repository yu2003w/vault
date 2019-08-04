/*
整数划分问题
将最大加数n1不大于m的划分个数记作q(n,m)
n = n1 + n2 + n3 + ... + nk (n1 >= n2 >= n3 ... >= nk)

q(n,m) = 0    --- n < 1, m < 1
         1    --- n =1, m =1
         q(n, n) --- n < m
         1 + q(n, m - 1)   --- n = m
         q(n, m-1) + q(n-m, m)  --- n > m > 1
*/

#include <iostream>
using namespace std;

int q(int n, int m) {
    if (n < 1 || m < 1) return 0;
    if (n == 1 || m == 1) return 1;
    if (n < m) return q(n, n);
    if (n == m) return q(n, m-1) + 1;
    return q(n, m-1) + q(n-m, m);
}

int main(int argc, char** argv) {
    cout<<q(3,3)<<endl;
	cout<<q(6,1)<<endl;
    cout<<q(6,5)<<endl;
}

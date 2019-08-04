#include <iostream>
using namespace std;

/* Place M apples into N plates, how many? */

int a[100] = {0};
void print(int n) {
	for (int i = 1; i <= n; i++)
	cout<<a[i]<<" ";
	cout<<endl; 
}
int backtrack(int k, int m, int n) {
    static int total = 0;
    for (int i = a[k-1]; i <= m && k <= n; i++) {
        m -= i;
        a[k] = i;
        if (m == 0 && k == n) {
            total++; 
            print(n);
		}
        else if (k < n)
            backtrack(k+1, m, n);
        m += i;
    }
    return total;
}
int main(int argc, char ** argv) {
    cout<<backtrack(1, 7, 3)<<endl;
}

/*
prime ring problem
1...20 in a ring, adjacent numbers should be prime.
*/
#include <iostream>
#include <cmath>
using namespace std;

// array for numbers
int a[20];
// array indicate whether this element is available
int b[20];

// check whether this number is prime
int primeCheck(int va) {
    int k = 2, sva = sqrt(va);
    while (k <= sva && va % k != 0) k++;
    if (k > sva) return 1;
    return 0;
}

void outputSolution(int n) {
    static int total;
    total++;
    cout<<total<<":"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// search starting from number i, n is the largest number
void backtrack(int t, int n) {
    if (n > 20) {
        cout<<"too much numbers"<<endl;
        return;
    }
	//cout<<"calling backtrack("<<t<<")"<<endl; 
    for (int i = 1; i <= n; i++) {
        if (!b[i-1] && (t == 1 || primeCheck(a[t-2] + i))) {
            a[t-1] = i;
            b[i-1] = 1;
            if (t == n) {
                if (primeCheck(a[t-1] + a[0])) {
                    outputSolution(n);
                }
            } else {
            	    //cout<<i<<" selected"<<endl; 
                    backtrack(t+1, n);
            }
            b[i-1] = 0;
            //cout<<i-1<<" back, ";
        }
    }
    //cout<<"return backtrack("<<t<<")"<<endl;
}

int main(int argc, char ** argv) {
    backtrack(1, 6);
}

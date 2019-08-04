#include <iostream>
using namespace std;

int a[8];
bool b[8], c[16], d[16];

void print() {
    static int total = 0;
    total++;
    for (int i = 0; i < 8; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<total<<endl;
}

int iterativeBacktrack(int k) {
    while (k > 0) {
    	a[k] = a[k] + 1;
    	while (a[k] <)
    	/*
        for (int i = 0; i < 8; i++) {
            if (!b[i] && !c[k+i-1] && !d[k-i+6]) {
                a[k - 1] = i+1;
                b[i] = 1;
                c[k+i-1] = true;
                d[k-i+6] = true;
                
                if (k == 8) {print(); b[i] = false; c[k+i-1] = false; d[k-i+6] = false;}
                else {
                    cout<<i<<" "<<k<<endl; 
                    k++; i = 0;}
            }
        }
        k--;
        */
    }
}
int main(int argc, char ** argv) {
    iterativeBacktrack(1);
}

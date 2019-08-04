#include <iostream>
using namespace std;

int a[8], b[8], c[16], d[16];
void print() {
    static int total = 0;
    total++;
    for (int i = 0; i < 8; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<total<<endl;
}

void backtrack(int k) {
    for (int i = 0; i < 8; i++) {
        if (!b[i] && !c[k+i-1] && !d[k-i+6]) {
            a[k-1] = i + 1;
            b[i] = 1;
            c[k+i-1] = 1;
            d[k-i+6] = 1;
            if (k == 8) print();
            else backtrack(k+1);
            b[i] = 0;
            c[k+i-1] = 0;
            d[k-i+6] = 0;
        }
    }
}
int main(int argc, char ** argv) {
    backtrack(1);
}

#include <iostream>
using namespace std;

/*
dataset {1, 2, 3..n}
list all sub datasets which contains r values of the whole dataset
*/
int a[100], b[100];

void print(int r);
void backtrack(int t, int n, int r) {
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            a[t-1] = i+1;
            b[i] = 1;
            if (t == r) print(r);
            else backtrack(t+1, n, r);
            b[i] = 0;
        }
    }
}

int main(int argc, char ** argv) {
    backtrack(1, 5, 3);
}

void print(int r) {
    for (int i = 0; i < r; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

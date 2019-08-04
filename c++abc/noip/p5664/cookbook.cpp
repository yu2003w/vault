#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    const long mod = 998244353;

    int n, m, ret = 0;
    cin>>n>>m;

    if (n < 1 || m < 1) {
        return 0;
    }

    int **a = new int * [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }

    return ret % mod;
}

void dumpInfo(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
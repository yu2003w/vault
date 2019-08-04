#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a:b;
}
void dump(int **a, int row, int col) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (a[i][j] > 0)
                cout<<"a["<<i<<","<<j<<"]="<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char ** argv) {
    int weight[11], value[11], n, totalw;
    cin>>n>>totalw;
    if (n < 1 || totalw < 0)
        return 0;
    for (int i = 1; i <= n; i++) {
        cin>>weight[i];
    }
    for (int i = 1; i <= n; i++) {
        cin>>value[i];
    }

    int ** m = new int* [n+1];
    for (int i = 0; i <= n; i++) {
        m[i] = new int[totalw+1];
        memset(m[i], 0, (totalw+1)*sizeof(int));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= totalw; j++) {
            if (weight[i] > j) {
                m[i][j] = m[i-1][j];
            } else {
                m[i][j] = max(m[i-1][j], m[i-1][j-weight[i]] + value[i]);
            }
        }

    cout<<"m[10, 67]="<<m[10][67]<<endl;
    dump(m, n, totalw);
    return 0;
}
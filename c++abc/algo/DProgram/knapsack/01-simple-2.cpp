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

int main(int argc, char** argv) {
    int n, totalw;

    cin>>n>>totalw;

    if (n <= 0 || totalw <= 0)
        return 0;
    int * weight = new int[n+1];
    int * value = new int[n+1];
    for (int i = 1; i <= n; i++) {
        cin>>weight[i]>>value[i];
    }

    int ** m = new int* [n+1];
    for (int i = 0; i <= n; i++) {
        m[i] = new int[totalw+1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = totalw; j > 0; j--) {
            if (weight[i] > j) {
                m[i][j] = m[i-1][j];
            } else {
                m[i][j] = max(m[i-1][j], m[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    cout<<"m[4,10]="<<m[4][10]<<endl;
    dump(m, n, totalw);

    for (int i = 0; i <= n; i++) {
        memset(m[i], 0, (totalw + 1)*sizeof(int));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalw; j++) {
            if (weight[i] > j) {
                m[i][j] = m[i-1][j];
            } else {
                m[i][j] = max(m[i-1][j], m[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<"m[4,10]="<<m[4][10]<<endl;
    dump(m, n, totalw);

    int * m1  = new int[totalw+1];
    memset(m1, 0, (totalw+1)*sizeof(int));
    for (int i = 1; i <= n; i++) {
        for (int j = totalw; j >= weight[i]; j--) {
                m1[j] = max(m1[j], m1[j-weight[i]]+value[i]);
        }
        for (int k = 1; k <= totalw; k++)
            m1[k] > 0 ? cout<<"m1["<<k<<"]="<<m1[k]<<" " : cout<<"";
        cout<<endl;
    }
    cout<<endl<<"m1[10]="<<m1[10]<<endl;

    // weight in sequence is not correct because 
    // f[i][v] = max(f[i-1][v] + f[i-1][v-weight[i]] + value[i])
    // in sequence, f[v] will be accumulated. It's not correct.
    /*
    memset(m1, 0, (totalw+1)*sizeof(int));
    for (int i = 1; i <= n; i++) {
        for (int j = weight[i]; j <= totalw; j++) {
                m1[j] = max(m1[j], m1[j-weight[i]]+value[i]);
        }
        for (int k = 1; k <= totalw; k++)
            m1[k] > 0 ? cout<<"m1["<<k<<"]="<<m1[k]<<" " : cout<<"";
        cout<<endl;
    }
    cout<<endl<<"m1[10]="<<m1[10]<<endl;
    */

    return 0;
}
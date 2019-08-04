#include <iostream>
#include <string.h>

using namespace std;

int max(int a, int b) {
    return a > b ? a:b;
}

void dump(int **a, int row, int col);

int msack(int **a, int * wei, int *v, int n, int w);

int main(int argc, char** argv) {
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
        memset(m[i], -1, (totalw+1)*sizeof(int));
    }

    int ret = msack(m, weight, value, n, totalw);
    cout<<"msack["<<n<<","<<totalw<<"]="<<ret<<endl;
    //cout<<"msack["<<8<<","<<65<<"]="<<msack(m, weight, value, 8, 65)<<endl;
    return 0;
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

int msack(int **a, int *wei, int *v, int n, int w) {
    if (n <= 0 || w < 0) return 0;

    if (a[n-1][w] == -1)
        a[n-1][w] = msack(a, wei, v, n-1, w);
    
    if (wei[n] > w) {
        a[n][w] = a[n-1][w];
    } else {
        if (a[n-1][w - wei[n]] == -1) {
            a[n-1][w-wei[n]] = msack(a, wei, v, n-1, w-wei[n]);
        }
        a[n][w] = max(a[n-1][w], a[n-1][w-wei[n]]+ v[n]);
    }
    //if (a[n][w] > 0)
    cout<<"msack["<<n<<","<<w<<"]="<<a[n][w]<<endl;
    return a[n][w];
}

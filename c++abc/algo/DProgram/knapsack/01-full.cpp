#include <iostream>
#include <string.h>
using namespace std;

/*
对于完全背包问题， f[i][v] = max{f[i-1][v-k*w[i]] + k*v[i] | 0<= k*w[i]<= v}
*/
int main(int argc, char **argv) {
    int totalw, n;
    cin>>totalw>>n;
    if (totalw <= 0 || n <= 0)
        return 0;
    int * weight = new int[n+1];
    int * value = new int[n+1];
    for (int i = 1; i <= n; i++) {
        cin>>weight[i]>>value[i];
    }

    int * f = new int[totalw+1];
    memset(f, 0, (totalw+1)*sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int vol = weight[i]; vol <= totalw; vol++) {
            if (f[vol] < (f[vol - weight[i]] + value[i]))
                f[vol] = f[vol - weight[i]] + value[i];
        }
        
        cout<<i<<"->"; 
        for (int vol = 1; vol <= totalw; vol++) {
        	cout<<f[vol]<<" ";
		}
		cout<<endl;
		
    }
    cout<<f[totalw]<<endl;
    return 0;
}

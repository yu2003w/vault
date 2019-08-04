#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

/*
sample input: 10 4
              2  1
              3  3
              4  5
              7  9
*/
int main(int argc, char ** argv) {
    int v, n;
    cin>>v>>n;
    if (v <= 0 || n <= 0)
        return 0;
    int * weight = new int[n];
    int * cost = new int[n];
    for (int j = 0; j < n; j++) {
        cin>>weight[j]>>cost[j];
    }

    int * f = new int[v+1];
    memset(f, 0, (v+1)*sizeof(int));
    for (int i = 1; i <= n; i++) {
        for (int vol = v; vol >= weight[i-1]; vol--) {
            if (f[vol - weight[i-1]] + cost[i-1] > f[vol]) {
                f[vol] = f[vol - weight[i-1]] + cost[i-1];
            }
        }
        
        /*
        cout<<i<<"->"; 
        for (int vol = v; vol > 0; vol--) {
        	cout<<f[vol]<<" ";
		}
		cout<<endl;
		*/
    }
    cout<<f[v]<<endl;
    return 0;
}

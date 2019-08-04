#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin>>n;
    if (n < 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin>>m;
        if (m < 1) continue;
        int * data = new int[m+1];
        // insert sort
        for (int j = 1; j <= m; j++) {
            cin>>data[0];
            int k = j;
            for (; data[k-1] > data[0]; k--) {
                data[k] = data[k-1];
            }
            data[k] = data[0];
        }
        
        /*
        for (int i = 1; i <= m; i++) cout<<data[i]<<" ";
        cout<<endl;
        */
        bool * f = new bool[data[m]+1];
        for (int v = 0; v <= data[m]; v++) f[v] = 0;
        int count = 0;
        for (int i = 1; i <= m; i++) {
            if (f[data[i]]) continue;
            f[data[i]] = true; 
            count++;
            for (int v = data[i]; v <= data[m]; v++) {
                if (f[v - data[i]]) f[v] = true;
            }
            
            /*
            cout<<i<<"->";
            for (int v = data[1]; v <= data[m]; v++) 
                cout<<f[v]<<" ";
            cout<<endl;
            */
            
        }
        
        cout<<count<<endl;
        delete []data;
        delete []f;
    }
   
}

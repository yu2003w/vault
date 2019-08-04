#include <iostream>
using namespace std;

/*
排队打水问题， n个人排队，r个水龙头，求所有人花费的最少打水时间的排法
*/
int main(int argc, char **argv) {
    int n, r;
    cin>>n>>r;
    if (n <= 0 || r <= 0)
        return 0;
    
    int * data = new int[n+1];
    int * sum = new int[r+1];
    // initialize
    for (int i = 1; i <= r; i++) sum[i] = 0;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        cin>>data[0];
        j = i;
        for (; data[0] < data[j-1]; j--) {
            data[j] = data[j-1];
        }
        data[j] = data[0];
    }
    
    /*
    for (int i = 1; i <= n; i++)
         cout<<data[i]<<" ";
    cout<<endl;
    */
    
    j = 0; int min = 0;
    for (int i = 1; i <= n; i++) {
        j++;
		if (j == r+1) j = 1;
        sum[j] += data[i];
        min += sum[j];
    }
    // cout<<sum[1]<<" "<<sum[2]<<endl;
    cout<<min<<endl;
}

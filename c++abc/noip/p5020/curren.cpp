#include <iostream>
using namespace std;

int process(int [], int m);
int main(int argc, char ** argv) {
    int n;
    cin>>n;
    int * ret = new int[n];
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
        ret[i] = process(data, m);
        delete []data;
    }
    for (int i = 0; i < n; i++)
        cout<<ret[i]<<endl;
}

int process(int data[], int m) {
    int count = m;
    for (int i = m; i > 1; i--) {
        int temp = data[i];
        for (int j = i - 1; j > 0; j--) {
            temp %= data[j];
            //cout<<i<<" "<<temp<<endl;
            if (temp == 0) {
                count--;
                break;
            }
        }
    }
    return count;
}

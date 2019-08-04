#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin>>n;
    int * s = new int[n+1];
    int * e = new int[n+1];
    bool * act = new bool[n+1];
    // insert sort based on ending time
    for (int i = 1; i <= n; i++) {
        cin>>s[0]>>e[0];
        int j = i;
        for (;e[0] < e[j-1]; j--) {
            e[j] = e[j-1];
            s[j] = s[j-1];
        }
        e[j] = e[0];
        s[j] = s[0];
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= n; i++) {
        cout<<e[i]<<" ";
    }
    cout<<endl;
    */

    // greedy
    act[1] = true;
    int j = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] >= e[j]) {
            act[i] = true;
            j = i;
        }
        else act[i] = false;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (act[i]) {
            count++;
            cout<<s[i]<<" "<<e[i]<<endl;
        }
    }
    cout<<count;
}

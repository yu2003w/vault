#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    unsigned long long n, k;
    cin>>n>>k;
    if (n < 1 || k < 0) {
        return 0;
    }
    int tmp = n;
    char * result = new char[n+1];
    n = (unsigned long long)1 << (n-1);
    // this is not correct, may leads to overflow for n = 64 and k = 1<<64 - 1
    // k += 1;
    int i = 0;
    while (n > 1) {
        if (k > (n - 1)) {
            result[i++] = '1';
            k = (n << 1) - k - 1;
            //cout<<"1 "<<n<<" "<<k<<endl;
        } else {
            result[i++] = '0';
            //cout<<"0 "<<n<<" "<<k<<endl;
        }
        n = n >> 1;
    }

    if (k == 1) {
        result[i++] = '1';
    } else {
        result[i++] = '0';
    }

    result[i] = '\0';
    for (int i = 0; i < tmp; i++)
         cout<<result[i];
    cout<<endl;

}
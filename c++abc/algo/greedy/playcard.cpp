#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin>>n;
    if (n < 0)
        return 0;
    int * data = new int[n];
    int avg = 0;
    for (int i = 0; i < n; i++) {
        cin>>data[i];
        avg += data[i];
    }
    avg /= n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        data[i] -= avg;
        if (data[i] != 0) {
            count++;
            data[i+1] += data[i];
        }
    }
    cout<<count;
}
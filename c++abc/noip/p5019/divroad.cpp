#include <iostream>
using namespace std;
/*
sample input:
6
4 6 2 5 3 5
*/
int repair(int data[], int start, int end, int min);

int main(int argc, char** argv) {
    int n;
    cin>>n;
    if (n < 0)
    return 0;
    int * data = new int[n];
    
    int min = 0;
    for (int i = 0; i < n; i++) {
        cin>>data[i];
        if (i == 0) {
            min = data[0];
        } else if (min > data[i]) {
            min = data[i];
        }
    }

    cout<<repair(data, 0, n, min);
    delete []data;
    return 0;
}

int repair(int data[], int start, int end, int min) {
    int sum = min;
    int nmin = 0;
    for (int i = start; i < end; i++) {
        data[i] -= min;
        
        if (data[i] == 0) {
            if (i > start) {
                sum += repair(data, start, i, nmin);
                start = i+1;
            }
            else
            start += 1;
        } else {
            if (i == start) {
                nmin = data[i];
            } else if (data[i] < nmin) {
                nmin = data[i];
            }
        }
    }
    if (start < end) {
        sum += repair(data, start, end, nmin);
    }
    return sum;
}

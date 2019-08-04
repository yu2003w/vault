#include <iostream>
using namespace std;

// TODO: how about use bucket as a range, then sort within each bucket
int main(int argc, char** argv) {
    int num[] = {11, 4, 19, 17, 99, 63, 22, 45, 56, 78, 11, 99, 63, 15, 22};

    int b[100];
    for (int i = 0; i < 100; i++)
        b[i] = -1;
    
    for (int i = 0; i < 15; i++) {
        if (num[i] < 100 && num[i] >= 0) {
            b[num[i]]++;
        }
    }
    
    for (int i = 0; i < 100; i++) {
        if (b[i] > -1) {
           for (int j = -1; j < b[i]; j++) 
                cout<<i<<" ";
        }
    }
    cout<<endl;
}

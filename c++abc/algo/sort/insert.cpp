#include <iostream>
using namespace std;

void insert_sort(int data[], int n) {
    for (int i = 2; i <= n; i++) {
        if (data[i] < data[i - 1]) {
            data[0] = data[i];
            int j = i -1;              
            for (; data[0] < data[j]; j--) {
                data[j + 1] = data[j]; 
            }
            data[j + 1] = data[0];
        }
    }
}

int main(int argc, char ** argv) {
    // take data[0] as sentinel
    int num[] = {-1, 11, 4, 19, 17, 99, 63, 22, 45, 56, 78};
    insert_sort(num, 10);
    for (int i = 1; i < 11; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

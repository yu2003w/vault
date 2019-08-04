#include <iostream>
using namespace std;

int partition(int data[], int low, int high) {
    data[0] = data[low];
    while (low < high) {
        while (low < high && data[high] >= data[0]) high--;
        data[low] = data[high];
        while (low < high && data[low] <= data[0]) low++;
        data[high] = data[low];
    }
    data[low] = data[0];
    return low;
}

void quick_sort(int data[], int low, int high) {
    if (low < high) {
        int pivotLoc = partition(data, low, high);
        quick_sort(data, low, pivotLoc - 1);
        quick_sort(data, pivotLoc + 1, high);
    }
}

int main(int argc, char ** argv) {
    int num[] = {-1, 11, 4, 19, 17, 99, 63, 22, 45, 56, 78};
    quick_sort(num, 1, 10);
    for (int i = 1; i < 11; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

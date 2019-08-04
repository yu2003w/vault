#include <iostream>
using namespace std;

int binarySearch(int data[], int a, int len) {
    int start = 0, end = len - 1;
    while (start <= end) {
        int mid = (start + end)/2;
        if (a == data[mid]) {
            return mid;
        }
        if (a > data[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main (int argc, char ** argv) {
    int data[] = { 1, 3, 6, 8, 11, 22, 24, 27, 28, 31};
    cout<<binarySearch(data, 19, 10)<<endl;
    cout<<binarySearch(data, 34, 10)<<endl;
    cout<<binarySearch(data, 22, 10)<<endl;
}

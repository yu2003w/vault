#include <iostream>
using namespace std;

// sort array ascending
void select_sort(int data[], int n) {
    for (int i = 0; i < n; i++) {
    	int k = i;
        for (int j = i + 1; j < n; j++) {
            if (data[k] > data[j]) {
               k = j;
            }
        }
        if (k != i) {
        	int temp = data[k];
        	data[k] = data[i];
        	data[i] = temp;
		}
	}    
}

int main(int argc, char ** argv) {
    int num[] = {11, 4, 19, 17, 99, 63, 22, 45, 56, 78};
    select_sort(num, 10);
    for (int i = 0; i < 10; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

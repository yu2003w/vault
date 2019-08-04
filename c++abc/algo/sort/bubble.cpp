#include <iostream>
using namespace std;

/*
TODO: 
1, bubbled from 0 to n, how to make bubble from n to 0
2, how to optimize the code
*/
void bubble_sort(int data[], int n) {
	int i = 1;
    for (; i < n; i++) {
    	bool ex = false;
        for (int j = 0; j < n - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                ex = true;
            }
        }
        if (ex == false)
         break;
    }
    cout<<i<<endl;
}

int main(int argc, char ** argv) {
    //int num[] = {11, 4, 19, 17, 99, 63, 22, 45, 56, 78};
    int num[] = {11, 4, 19, 17, 22, 45, 56, 63, 78, 99 };
    bubble_sort(num, 10);
    for (int i = 0; i < 10; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

#include <iostream>
#include <string.h>
using namespace std;

//最长不下降子序列
int main(int argc, char **argv) {
    int data[] = {13, 7, 9, 16, 38, 24, 37, 18, 44, 19, 21, 22, 63, 15};
    int * len = new int[14];
    int * pos = new int[14];
    for (int i = 0; i < 14; i++) {
    	len[i] = 1;
    	pos[i] = -1;
	}

    int lenp = 0, k = 0;
    // why i = 12 rather than 13 here?
    for (int i = 12; i >= 0; i--) {
        lenp = 0, k = 0;
        for (int j = i+1; j < 14; j++) {
            if (data[j] >= data[i] && len[j] > lenp) {
                lenp = len[j];
                k = j;
            }
        }
        if (lenp > 0) {
            len[i] = lenp + 1;
            pos[i] = k;
        }
    }
    for (int i = 0; i < 14; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 14; i++) {
        cout<<len[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 14; i++) {
        cout<<pos[i]<<" ";
    }
    cout<<endl;
    k = 0;
    for (int i = 1; i < 14; i++) {
    	if (len[i] > len[k]) k = i;
	}
	cout<<"longest sequence is "<<len[k]<<endl;
	while (k != -1) {
		cout<<data[k]<<" ";
		k = pos[k];
	}
}

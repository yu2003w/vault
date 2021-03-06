#include <iostream>
using namespace std;

void merge(int data[], int s, int m, int t) {
	int a1 = m - s + 1;
	int a2 = t - m;
    int * la = new int[a1];
    int * ra = new int[a2];
    for  (int i = 0; i < a1; i++)
        la[i] = data[s + i];
    for  (int i = 0; i < a2; i++) {
        ra[i] = data[m + 1 + i];
    }
    
    int i = 0, j = 0, k = s;
    while (i < a1 && j < a2) {
        if (la[i] < ra[j]) {
            data[k++] = la[i++];
        } else {
            data[k++] = ra[j++];
        }
    }
    while (i < a1) {
        data[k++] = la[i++];
    }
    while (j < a2) {
        data[k++] = ra[j++];
    }
}

void msort(int data[], int s, int t) {
    if (s == t) return;
    else {
        int m = (s + t - 1) / 2;
        msort(data, s, m);
        msort(data, m+1, t);
        merge(data, s, m, t);
    }
}

int main(int argc, char ** argv) {
    int num[] = {11, 4, 19, 17, 99, 63, 22, 45, 56, 78};
    msort(num, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

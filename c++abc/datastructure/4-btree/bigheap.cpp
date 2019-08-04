#include <iostream>
using namespace std;

void swap(int &, int &);
int heapadjust(int data[], int start, int end) {
	//data[0] = data[start];
	for (int j = start *2; j <= end; j*= 2) {
		if (j < end && data[j] < data[j+1]) j++;
		if (data[start] > data[j]) break;
		swap(data[start], data[j]);
		start = j;
	}
	//data[start] = data[0];
}

void heapsort(int data[], int len) {
	for (int i = len/2; i > 0; i--) {
		heapadjust(data, i, len); 
	}
	for (int i = len; i>1; i--) {
		swap(data[1], data[i]);
		heapadjust(data, 1, i-1);
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char **argv) {
	int test[11] = {-1, 22, 7, 9, 3, 4, 1, 15, 24, 16, 30};
	heapsort(test, 10);
	for (int i = 1; i < 11; i++)
	    cout<<test[i]<<" ";
	cout<<endl;
} 



#include <iostream>
using namespace std;

// this example is to establish small heap and learn how to debug
int heapsize = 0;
void swap(int &, int&);
void put(int data[], int val) {
	if (heapsize >= 99) {
		cout<<"heap is full"<<endl;
		return;
	}
	data[++heapsize] = val;
	int cur = heapsize;
	int next = 0;
	while (cur > 1) {
		next = cur / 2;
		if (data[next] <= data[cur]) break;
		swap(data[next], data[cur]);
		cur = next;
	}
}
int get(int data[]) {
	if (heapsize < 1) {
		cout<<"heap is empty"<<endl;
		return -1;
	}
	int val = data[1];
	data[1] = data[heapsize--];
	// sort heap
	int cur = 1, next = cur*2;
	while (next <= heapsize ) {
		//cout<<"next="<<next<<" "<<data[cur]<<" "<<data[next]<<" "<<data[next+1]<<endl;
		if (data[next] > data[next+1]) next++;
		if (data[cur] < data[next]) break;
		//cout<<"ex"<<data[next]<<" "<<data[cur]<<endl;
		swap(data[next], data[cur]);
		cur = next;
		next = cur * 2;
	}
	return val;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char** argv) {
	int heap[15];
	int test[14] = {22, 34, 7, 9, 3, 4, 1, 15, 24, 16, 71, 30, 19, 23};
	for (int i = 0; i < 14; i++)
	    put(heap, test[i]);
	for (int i = 1; i <= 14; i++)
        cout<<heap[i]<<" ";
    cout<<endl;
	for (int i = 0; i < 14; i++)
	    cout<<get(heap)<<" ";
	cout<<endl;
}

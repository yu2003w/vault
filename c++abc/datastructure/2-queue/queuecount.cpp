#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int per[100], n, m;
	cin>>n>>m;
	for (int i = 0; i < n - 1; i++) {
		per[i] = i+1;
	}
	per[n-1] = 0;
	int p = 0, k = 1, cur = 0;
	while(p < n) {
		while (k < m) {
			k++;
			cur = per[cur];
		}
		cout<<per[cur]<<" "; 
		p++;
		per[cur] = per[per[cur]];
		k=1;		
	}
}

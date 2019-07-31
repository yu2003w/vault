#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	// tree has n nodes and m edge 
	int n, m, tree[100];
	int root, maxparent = 0, maxroot = 0;
	int child, parent; 
	cin>>n>>m;
	for (int i = 0; i < 100; i++) {
		tree[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin>>parent>>child;
		tree[child] = parent;
	}
	
	// find out root
	for (int i = 0; i < n; i++) {
		if (tree[i] == -1) {
			root = i; 
			break;
		}
	}
	
	// find the root with maximum child
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (tree[j] == i) 
			    sum++; 
		}
		if (maxparent < sum) {
			maxparent = sum;
			maxroot = i;
		}
	}
	cout<<"根节点 "<<root<<endl;
	cout<<"孩子最多节点 "<<maxroot<<endl; 
	for (int j = 0; j < n; j++) {
		if (tree[j] == maxroot) 
		    cout<<j<<" "; 
	} 
	return 0;
}

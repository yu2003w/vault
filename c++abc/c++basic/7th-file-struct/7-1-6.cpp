#include<iostream>
using namespace std;

int main(int argc, char** argv) {
	int n = -1;
    cin>>n;
    int data[10];
    for (int i = 0; i < n; i++)
        cin>>data[i];
    cout<<n<<endl;
    for (int i = 0; i < n; i++) {
    	cout<<data[i]<<" ";
	}
	cout<<endl;
} 

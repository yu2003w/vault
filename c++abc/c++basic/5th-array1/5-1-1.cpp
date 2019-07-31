#include<iostream> 
using namespace std;

int a1[5];
int main(int argc, char**argv) {
	for (int i=0; i<5; i++) {
		cout<<"a1["<<i<<"]="<<a1[i]<<",";
	}
	cout<<endl;
	int a2[5];
	for (int i=0; i<5; i++) {
		cout<<"a2["<<i<<"]="<<a2[i]<<",";
	}
	cout<<endl;
	//a2[5] = {1,2,3,4,5};
	int a3[5] = {1,2,3,4,5};
	for (int i=0; i<5; i++) {
		cout<<"a3["<<i<<"]="<<a3[i]<<",";
	}
}

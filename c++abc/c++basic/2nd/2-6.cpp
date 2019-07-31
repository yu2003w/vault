#include <iostream>
using namespace std;

int main(int argc, char**argv) {
	int x=4, y=5, z;
	z = x>y;
	cout<<"x>y ->"<<z<<endl; 
	z = x<=y;
	cout<<"x<=y ->"<<z<<endl; 
	z = x!=y;
	cout<<"x!=y ->"<<z<<endl;
	z = x==y;
	cout<<"x==y ->"<<z<<endl;
	
	int k = x>=y?x:y;
	cout<<k<<endl;
}

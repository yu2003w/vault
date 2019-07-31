#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a,b,c,d;
	// float d;
	cin>>a>>b>>c>>d;
	switch(d) {
		case 1:
			a++;
			cout<<a<<endl;
			break;
		case 2:
			b++;
			cout<<b<<endl;
		//	break;
		case 3:
			c++;
			cout<<c<<endl;
			break;
		default:
			cout<<"invalid index"<<endl;
	}
}

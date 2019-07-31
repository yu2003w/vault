#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a, b, c, max;
	cin>>a>>b>>c;
	if (a > b && a > c)
	    max = a;
	    //max = 0;
	else if (b > a && b > c)
	    max = b;
	else
	    max =c;
	cout<<"max number is "<<max<<endl;
	
	//min = (a>b) ? (b+c):(b*c);
	//min = ()?():();
	
	max = (a>b && a > c) ? a :((b >a && b > c)? b:c);
	cout<<"max number is "<<max<<endl;
}

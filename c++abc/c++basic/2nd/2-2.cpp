#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
	const double pi = 3.1415926;
	float r, height;
	
	cin>>r>>height;
	double bot_area = pi*r*r;
	double side_area = 2*pi*r*height;
	double sarea = 2*bot_area + side_area;
	cout<<setprecision(15)<<endl;
	cout<<"area="<<sarea<<endl;
	return 0; 
	
}

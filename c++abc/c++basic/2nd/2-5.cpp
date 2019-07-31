#include<iostream>
using namespace std;

int main(int argc, char**argv) {
	int x=0, y=5, z=2;
	int k = y/2;
	int l = y%2;
	cout<<"5/2="<<k<<endl;
	cout<<"5.0/2="<<5.0/2<<endl;
	cout<<"5%2="<<l<<endl;
	x= ++y;
	cout<<"x="<<x<<",y="<<y<<endl; 
	y=y+1;
	x=y;
	//x=y++;
	x=y;
	y=y+1;
	z= y++ -1;
	z= y++ + ++y; 
	l= z - (++y);
	cout<<"x="<<x<<","<<"z="<<z<<",l="<<l<<",y="<<y<<endl;
	x+=z;
	cout<<"x="<<x<<endl;
	x-=y;
	cout<<"x="<<x<<endl;
	y/=x;
	cout<<"y="<<y<<endl;
	y%=x;
	cout<<"y="<<y<<endl;
}

#include<iostream>
using namespace std;

int main(int argc, char** argv) {
	cout<<"size of int -> "<<sizeof(int)<<endl;
	cout<<"size of short -> "<<sizeof(short)<<endl;
	cout<<"size of long -> "<<sizeof(long)<<endl;
	cout<<"size of unsigned int -> "<<sizeof(unsigned int)<<endl;
	cout<<"size of unsigned short -> "<<sizeof(unsigned short)<<endl;
	cout<<"size of unsigned long -> "<<sizeof(unsigned long)<<endl;
	cout<<"size of float -> "<<sizeof(float)<<endl;
	cout<<"size of double -> "<<sizeof(double)<<endl;
	cout<<"size of char -> "<<sizeof(char)<<endl;
	cout<<"size of bool -> "<<sizeof(bool)<<endl;
	
	int i = 3.1415926;
	cout<<"i="<<i<<", sizeof i ->"<<sizeof(i)<<endl;
	i=4096000;
	short j = i;
	cout<<"i="<<i<<", j="<<j<<endl;
	//j = 18;
	j = 12;
	char c = j;
	cout<<"j="<<j<<", c="<<c<<endl;
	
	cout<<"12/8="<<j/8<<endl;
	float k =j/8;
	cout<<"k="<<k<<endl;
}



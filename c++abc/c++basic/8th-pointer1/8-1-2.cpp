#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int *pb= NULL;
	cout<<"pb="<<pb<<endl;
	if (pb != NULL)
	    cout<<"*pb="<<*pb<<endl;
	int b = 3;
	int *pc = &b;
	cout<<"pc="<<pc<<", *pc="<<*pc<<endl;
	int *pd = new int;
	cout<<"pd="<<pd<<", *pd="<<*pd<<endl;
	*pd = 6;
	cout<<"pd="<<pd<<", *pd="<<*pd<<endl;
	delete pd;
}

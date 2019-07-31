#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char** argv) {
	string s1="hello abc";
	char a1[20];
	strcpy(a1, s1.c_str());
	cout<<a1<<endl;
	char a2[10]= "hello";
	string s2;
	s2 = a2;
	cout<<s2;
}

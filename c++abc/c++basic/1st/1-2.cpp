#include<iostream>

using namespace std;

// program to demo standard input and standard output
int main(int argc, char** argv) 
{
	int a,b,c;
	// input 
	cin>>a>>b>>c;
	// output, modify code to output value of abc in reverse order
	cout<<a<<b<<c<<endl;
	
	scanf("%d%d%d", &a,&b,&c);
	printf("%d", c);
	
	return 0;
}

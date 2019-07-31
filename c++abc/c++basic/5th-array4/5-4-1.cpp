#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	char str[100] = "hello world";
	cout<<str<<endl;
	for (int i = 0; i<100; i++) 
	    cout<<str[i];
	cout<<strlen(str)<<endl;
	char str1[5] = {'a','b','c','d','e'};
	cout<<endl<<str1<<endl;
	
	//统计输入字符串的字数
	char str2[100];
	cin.getline(str2,100);
	if (cin.fail()) {
		cout<<"invalid input"<<endl;
		return 1;
	}
	int count = 0; 
	while(str2[count] != '\0')
	    count++;
	cout<<count<<endl;
	cout<<sizeof(str2)<<endl;
	cout<<strlen(str2)<<endl;
}

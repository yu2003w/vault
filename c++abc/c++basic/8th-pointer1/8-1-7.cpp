#include <iostream>
#include <string.h>
using namespace std;

char * substring(int i, char * src);
int main(int argc, char** argv) {
	char *str = "This is string";
	cout<<str<<endl;
	cout<<str+3<<endl;
	cout<<str[3]<<endl;
	char *tmp = substring(15, str);
	if (tmp != NULL) {
		cout<<tmp<<endl;
	}
    tmp = substring(5, str);
	cout<<tmp<<endl;
}

char * substring(int index, char * src) {
	int len = strlen(src);
	if (index > len) {
		return NULL;
	} else {
		return src+index;
	}
}

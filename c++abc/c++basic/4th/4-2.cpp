#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int j = 10;
	while (j > 0) {
		cout<<j;
		j--;
	}
	cout<<endl;
	
	j = 10;
	do {
		cout<<j;
		j--;
	} while(j>0);
}

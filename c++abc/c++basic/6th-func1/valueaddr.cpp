#include <iostream>
using namespace std;

int m(int x, int y) {
	int k = 1;
	for (int i=2; i <= x; i++) {
		if (x % i == 0 && y % i == 0) {
			k = i;
		}
	}
	return k;
}

void swap(int x, int y) {
	cout<<"in func x addr->"<<&x<<endl<<"y addr->"<<&y<<endl;
	cout<<x<<" "<< y<<endl;
	int temp = x;
	x= y;
	y = temp;
	cout<<x<<" "<<y<<endl;
}
int main() {
	int x, y;  
	x = 15, y =6;
	int ret = m(x, y);
	cout<<ret<<endl;
	cout<<"x addr->"<<&x<<endl<<"y addr->"<<&y<<endl; 
	swap(x,y);
	cout<<"out func "<<x<<" "<<y<<endl;
	
}





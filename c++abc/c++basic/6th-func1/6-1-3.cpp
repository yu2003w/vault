#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	int tmp = 0;
	cout<<tmp<<" "<<x<<" "<<y<<endl;
	tmp = x;
	x = y;
	y = tmp;
	cout<<tmp<<" "<<x<<" "<<y<<endl;
}

int main(int argc, char** argv) {
	int m = 5, n = 6;
	swap(m,n);
	cout<<m<<" "<<n<<endl;
	m = 9, n = 8;
	swap(m,n);
	cout<<m<<" "<<n<<endl;
}

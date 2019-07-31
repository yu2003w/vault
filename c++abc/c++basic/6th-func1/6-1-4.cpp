#include <iostream> 
using namespace std;

int x, y;
int gcd(int, int);
int lcm();

int main(int argc, char** argv) {
	cin>>x>>y;
	cout<<lcm()<<endl;
	cout<<sizeof(unsigned long long)<<endl;
	unsigned long val = 1;
	val = val << 63;
	cout<<val<<endl;
	return 0;
}

int gcd(int x, int y) {
	cout<<"x="<<x<<",y="<<y<<endl;
	int r = x%y;
	while (r != 0) {
		x = y;
		y = r;
		r = x%y; 
	}
	return y;
}
int lcm() {
	cout<<"x="<<x<<",y="<<y<<endl;
	return (x-1)*(y-1)/gcd(x-1,y-1);
}

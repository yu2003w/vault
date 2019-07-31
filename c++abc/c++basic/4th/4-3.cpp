#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int m, n, gcd;
	do {
		
	} while ();
	cin>>m>>n;
	gcd = m>n? m:n;
	while (gcd > 1 && (m % gcd !=0 || n % gcd != 0))
	    gcd--;
	cout<<gcd<<endl;
	
	int max = m>n ? m : n;
	int min = m>n ? n : m;
    int r = max % min;
	while (r != 0) {
		max = min;
		min = r;
		r = max % min;
	}
	cout<<min<<endl;
	return 0;
}

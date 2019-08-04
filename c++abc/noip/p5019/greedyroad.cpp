#include <iostream>
using namespace std;

/*
using greedy algo
*/
int main(int argc, char** argv) {
	int n;
	cin>>n;
	if (n <= 0)
	    return 0;
	    
	int num1 = 0, num2 = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin>>num2;
		sum += num2 > num1? num2 - num1:0;
		num1 = num2;
	}
	cout<<sum;
}

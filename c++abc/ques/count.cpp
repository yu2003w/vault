#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*noi.openjudge.cn, 1.9->8, 白细胞计数 */
int main(int argc, char**argv) {
	int n;
	float data[300];
	cin>>n;
	if (n <= 2 || n > 300) {
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		cin>>data[0];
		int j = i;
		for (; data[j] < data[0]; j--) {
			data[j+1] = data[j];
		}
		data[j+1] = data[0];
	}
	 
	double avg, maxabs = 0;
	for (int i = 2; i < n; i++) {
		avg += data[i];
	}
	avg /= (n-2);
	
	for (int i = 2; i < n; i++) {
		double tmp = abs(data[i] - avg);
		if (tmp > maxabs)
		    maxabs = tmp;
	}
	
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<avg<<" "<<maxabs<<endl;
}

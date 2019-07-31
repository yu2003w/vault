/*
N个人围成一圈，从第一个人开始报数，数到M的人出圈，
然后从下一个人开始报数，数到M的人出圈； 
输出依次出圈的人的编号。
注意：N的数量不超过100，并且不少于5 
*/
 
#include <iostream> 
using namespace std;

int main(int argc, char** argv) {
	int m, n;
	cin>>n>>m;
	
	if (n < 0 || m <0 || n < m) {
		cout<<"invalid input"<<endl;
		return -1;
	}
	bool data[100];
	for (int i=0; i<n; i++) {
		// false -- in, true -- out
		data[i] = false;
	}
	for (int j=0, i=0; j < n; j++) {
		for (int k=1; k <= m;) {
			if (data[i] == false) {
				if (k == m) { 
			        data[i] = true;
			        cout<<i+1<<" ";
		        }
				k++;
			}
			
			if (++i == n) {
				i = 0;
			} 
		}	
	}
	
}

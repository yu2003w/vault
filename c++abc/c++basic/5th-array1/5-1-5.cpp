/*
N����Χ��һȦ���ӵ�һ���˿�ʼ����������M���˳�Ȧ��
Ȼ�����һ���˿�ʼ����������M���˳�Ȧ�� 
������γ�Ȧ���˵ı�š�
ע�⣺N������������100�����Ҳ�����5 
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

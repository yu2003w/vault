#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a[5] = {78,96};
	a[2] = 54, a[3] = 29, a[4] = 23;
	for (int i=0; i< 5; i++) {
		cout<<"a["<<i<<"]="<<a[i]<<"," ;
	}
	cout<<endl;
	//����ѭ���ṹ��������a��Ԫ�����¸�ֵ��
	// ÿ��ֵΪa[0] + i*5, ���ҽ���Ԫ��ֵ������� 
	 
}

#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	cout<<"������ʮ������"<<endl;
	int num, d;
	cin>>num;
	cout<<"��ָ��������"<<endl;
	cin>>d;
	int stack[5], i = 0;
	do {
		if (i > 5) {
			cout<<"stack overflow!"<<endl;
			break;
		}
		stack[i++] = num % d;
		cout<<stack[i-1];
		num /= d;

	} while (num != 0);
	cout<<"ת�������"<<endl;
	for (int j = i-1; j >= 0; j--) {
		cout<<stack[j];
	}

}

/*
��ϡ�������k*3�ľ�����
ע�⣺ϡ�����Ĺ�ģ������100*100 
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)  {
	const int row = 100;
	const int col = 100;
	int matrics[row][col];
	for (int i = 0; i < row; i++) 
	    for (int j = 0; j < col; j++)
	        matrics[i][j] = 0;
	int rrow, rcol;
	cout<<"����������������������"<<endl;
	cin>>rrow>>rcol; 
	if (cin.fail()) {
		cout<<"����Ĳ�������ȷ"<<endl;
		return 1; 
	}
	
	// ���ж������������������������Χ���������
	 
	for (int i = 0; i < rrow; i++) 
	    for (int j = 0; j < rcol; j++) {
	    	cin>>matrics[i][j];
		}
	for (int i = 0; i < rrow; i++) 
	    for (int j = 0; j < rcol; j++)	    	
		    if (matrics[i][j] !=0) {
		    	/*
		    	���޸Ĵ��룬��ϡ�����洢��һ����ά�����У�Ȼ���������
				���������ά��֤������ 
		    	*/
		    	cout<<i+1<<j+1<<matrics[i][j]<<endl;
			}
}

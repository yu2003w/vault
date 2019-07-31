/*
将稀疏矩阵用k*3的矩阵简记
注意：稀疏矩阵的规模不超过100*100 
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
	cout<<"请输入矩阵的行数和列数："<<endl;
	cin>>rrow>>rcol; 
	if (cin.fail()) {
		cout<<"矩阵的参数不正确"<<endl;
		return 1; 
	}
	
	// 请判断输入的行数和列数在正常范围，补充代码
	 
	for (int i = 0; i < rrow; i++) 
	    for (int j = 0; j < rcol; j++) {
	    	cin>>matrics[i][j];
		}
	for (int i = 0; i < rrow; i++) 
	    for (int j = 0; j < rcol; j++)	    	
		    if (matrics[i][j] !=0) {
		    	/*
		    	请修改代码，将稀疏矩阵存储在一个二维数组中，然后再输出。
				并先输出二维举证的行数 
		    	*/
		    	cout<<i+1<<j+1<<matrics[i][j]<<endl;
			}
}

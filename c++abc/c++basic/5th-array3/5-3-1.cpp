#include <iostream> 
using namespace std;

int main(int argc, char** argv) {
	const int row = 4;
	const int col = 3;
	int direct[4][3] = {{2,1,5},{3,8,2},{9,7,0},{6,8,1}};
	for (int i = 0; i < row; i++) {
	    for (int j=0; j < col; j++) 
	    	cout<<direct[i][j]<<" ";
	    cout<<endl;
	}
	
}


#include <iostream>
#include <string.h>
using namespace std;

// using adjacent matrix to construct undirection graph
int main(int argc, char ** argv) {
    int ug[5][5];
    
    cout<<sizeof(ug)<<endl;
    
    memset(ug, 0, sizeof(ug));
    ug[1][2] = 1;
	ug[1][3] = 1;
    ug[1][4] = 1;
    
    ug[2][1] = 1;
    ug[2][3] = 1;
    ug[2][4] = 1;
    
    ug[3][1] = 1;
    ug[3][2] = 1;
    
    ug[4][1] = 1;
    ug[4][2] = 1;
    
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            cout<<ug[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


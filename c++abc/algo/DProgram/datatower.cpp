#include <iostream>
using namespace std;

/*
       13            |    13
     11   8          |    11   8
   12   7  26        |    12   7   26
  6  14  15  8       |    6    14  15   8
12  7  13  24 11     |    12   7   13   24  11
*/


int main(int argc, char **argv) {
    int n;
    /*
    data[x][y][0]  ---  origin value
    data[x][y][1]  ---  maximum value
    data[x][y][2]  ---  direction
    */
    int data[50][50][3];
    cin>>n;
    cout<<"number of rows is "<<n<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <=i; j++) {
            cin>>data[i][j][0];
            data[i][j][1] = data[i][j][0];
            data[i][j][2] = 0;
        }
    
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++) {
            if (data[i+1][j][1] > data[i+1][j+1][1]) {
                data[i][j][1] += data[i+1][j][1];
                data[i][j][2] = 0;
            } else {
                data[i][j][1] += data[i+1][j+1][1];
                data[i][j][2] = 1;
            }
        }
    cout<<"max="<<data[0][0][1]<<endl;
    int col = 0;
    for (int i = 0; i < n; i++) {
        cout<<data[i][col][0]<<" ";
        col += data[i][col][2];
    }

}

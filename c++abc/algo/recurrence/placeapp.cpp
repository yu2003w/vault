#include <iostream>
using namespace std;
/*
将M个苹果放到N个盘子里
当m>n时分为两类：1， 有至少一个盘子为空， cnt[m][n-1]
2, 所有的盘子都不为空，cnt[m-n][n]
*/
int main(int argc, char ** argv) {
    int a, b;
    cin>>a>>b;
    int cnt[11][11];
    for (int m = 0; m < 10; m++) 
        for (int n = 0; n < 10; n++) {
            cnt[m][n] = 1;
            if (m == 0 || n == 1) cnt[m][n] = 1;
            else if (m >= n) {
                cnt[m][n] = cnt[m][n-1] + cnt[m-n][n];
            } else
            {
                cnt[m][n] = cnt[m][m];
            }
        }

    cout<<cnt[a][b]<<endl;
}


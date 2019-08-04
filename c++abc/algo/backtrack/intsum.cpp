#include <iostream>
using namespace std;

int a[100] = {2};
/*
list all datasets whose sum equals to specified value
*/
void print(int end) {
    static int total = 0;
    if (end == 0) {
        total = 0;
        return;
    }
    for (int i = 1; i < end; i++) {
        cout<<a[i]<<"+";
    }
    cout<<a[end]<<endl;
    total++;

}
void backtrack(int start, int val, int num) {
    for (int i = a[start - 1]; i <= val; i++) {
        if (i < num) {
            a[start] = i;
            val -= i;
            if (val == 0) print(start);
            else backtrack(start+1, val, num);
            val += i;
        }
    }
}

int main(int argc, char ** argv) {
    cout<<"5="<<endl;
    backtrack(1, 5, 5);
    print(0);
    cout<<"8, 6="<<endl;
    backtrack(1, 8, 6);
}

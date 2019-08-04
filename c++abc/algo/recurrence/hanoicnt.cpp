#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    /*
    hanoi count problem, hn= 2*hn-1 + 1
    */
    int n, sum = 0, h1 = 1, hi = 0;
    cin>>n;
    for (int i = 2; i < n; i++) {
        hi = 2 * h1 + 1;
        h1 = hi;
    }
    cout<<hi<<endl;
}

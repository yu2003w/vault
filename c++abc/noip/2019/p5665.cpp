#include <iostream>
using namespace std;

// process data of type 0
unsigned long long process0(int);

// process data of type 1
unsigned long long process1(int); 

int main(int argc, char**argv) {
    int n, type;
    cin>>n>>type;
    if (n < 0 || type < 0 || type > 1) {
        return 0;
    }

    if (type == 0) {
        cout<<process0(n);
    } else {
        cout<<process1(n);
    }
    return 0;
}
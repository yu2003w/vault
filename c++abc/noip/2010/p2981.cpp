#include <iostream>
using namespace std;

struct pos {
    int x;
    int y;
};

// construct graph to store rocks information
int search(int k);
int main(int argc, char**argv) {
    int n;
    struct pos spos, tpos;
    cin>>n>>spos.x>>spos.y>>tpos.x>>tpos.y;
    if (n < 1 || n > 20000) {
        return 0;
    }

    pos * rocks = new struct pos[n];
    // read rocks position
    for (int i = 0; i < n; i++) {
        cin>>rocks[i].x>>rocks[i].y;
    }
    cout<<search(1)<<endl;
    return 0;
}
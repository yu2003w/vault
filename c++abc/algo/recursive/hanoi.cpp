#include <iostream>
using namespace std;

/*
move from A to B
*/
void move(int i, char a, char b) {
    cout<<i<<"  "<<a<<"->"<<b<<endl;
}
int hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        move(1, a, b);
    }
    else {
        hanoi(n-1, a, c, b);
        move(n, a, b);
        hanoi(n-1, c, b, a);
    }
}

int main(int argc, char** argv) {
    cout<<"hanoi 3"<<endl;
    hanoi(3, 'A', 'B', 'C');
    cout<<"hanoi 5"<<endl;
    hanoi(7, 'A', 'B', 'C');
}

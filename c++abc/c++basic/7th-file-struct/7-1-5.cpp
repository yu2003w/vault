#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    ifstream infile("in.txt");
    int n = -1;
    infile>>n;
    int data[10];
    for (int i = 0; i < n; i++)
        infile>>data[i];
    cout<<n<<endl;
    infile.close(); 
    for (int i = 0; i < n; i++) {
    	cout<<data[i]<<" ";
	}
	cout<<endl;
}

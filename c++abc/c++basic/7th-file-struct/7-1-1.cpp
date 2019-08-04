#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	char fname[254];
	char fdata[512];
	cin>>fname;
	//cin.get(fname, 254);
	// fstream.app missed
	fstream fs(fname, fstream::in | fstream::out| fstream::app);
	if (!fs.good()) {
		cout<<"failed open"<<endl;
		return 1;
	}
	cout<<"content of "<<fname<<" as below,"<<endl;
	while (!fs.eof() && !fs.bad()) {
		fs.getline(fdata, 512);
		cout<<fdata<<endl;
	}
	char ending[]="I have mastered file operations.\n";
	fs.clear();
	fs.write(ending, strlen(ending));
	fs.close();
}

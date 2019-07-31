#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ofstream outfile("data.txt");
	if (!outfile.good()) {
		cout<<"无法打开文件data.txt"<<endl;
		return 1;
	}
	outfile<<"data in line 1."<<endl;
	outfile<<"data in line 2."<<endl;
	/*
	outfile.seekp(17, ios::beg);
	outfile<<"data inserted."<<endl;
	outfile.seekp(0, ios::end);
	*/
	outfile.close();
	char buf[1024];
	ifstream infile("data.txt");
	while(!infile.eof() && infile.good()) {
		infile.getline(buf, 1024);
		cout<<buf<<endl;
	}
	/*infile.clear();
	infile.seekg(17, ios::beg);
	infile.getline(buf, 1024);
	cout<<"Reading after seekg()"<<endl;
	cout<<buf<<endl;
	infile.seekg(0,ios::beg);
	infile.getline(buf, 1024);
	cout<<buf<<endl;
	*/
	infile.close();
	return 0;
	
}

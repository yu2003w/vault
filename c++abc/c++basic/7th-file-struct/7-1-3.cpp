#include <iostream>
#include <string.h>
using namespace std;

struct book {
	char name[256];
	char date[256];
	char author[256];
	const static bool reg = true;
	void print(); 
};

void book::print() {
    cout<<name<<","<<date<<","<<author<<endl;
}
int main(int argc, char** argv) {
	cout<<"���� "<<"�������� "<<"����"<<endl; 
	book b1= {"c++���", "2019-04-25", "Mike"};
	b1.print();
	cout<<book::reg;
	book b2;
	//b2.name = "hello abc";
	strcpy(b2.name, "�㷨���");
	strcpy(b2.date, "2019-04-30");
	strcpy(b2.author, "James");
	cout<<b2.name<<" "<<b2.date<<" "<<b2.author<<endl;
	
	book b3;
	cout<<"�������鼮��Ϣ"<<endl; 
	cin>>b3.name>>b3.date>>b3.author;
	cout<<b3.name<<" "<<b3.date<<" "<<b3.author;	 
}

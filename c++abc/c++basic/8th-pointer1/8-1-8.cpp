#include <iostream>
using namespace std;

struct student {
	char name[64];
	int seqnum;
	student * next;
};

int main(int argc, char** argv) {
	student stu1;
	student *p = new student;
	cin>>p->name>>(*p).seqnum;
	p->next = NULL;
	while (p != NULL) {
		cout<<p->name<<" "<<p->seqnum<<endl;
		p=p->next; 
	}
	delete p;
}

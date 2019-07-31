#include<iostream>

int main(int argc, char** argv){
	const int PI=3.1415926;
	const char* word="C++ program";
	std::cout<<"hello world"<<std::endl;
	int i;
	std::cout<<"i="<<i<<", &i="<<&i<<std::endl;
	
	int j;
	std::cout<<"j="<<j<<", &j="<<&j<<std::endl;
	int k;
	std::cout<<"k="<<k<<", &k="<<&k<<std::endl;
	
	std::cout<<"PI="<<PI<<", &PI="<<&PI<<std::endl;
	std::cout<<"word="<<word<<", &word="<<&word<<std::endl;
	
	/*
	scanf("%d", &j);
	printf("j=%d", j);
	*/
	//PI=3.14;
}



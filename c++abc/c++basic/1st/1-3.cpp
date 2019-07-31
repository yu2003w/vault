#include<iostream>

using namespace std;

int main(int argc, char** argv) {
	float area, height, top, bottom, shadowArea;
	top = 15, bottom = 25, shadowArea = 150;
	// calcuate height of trapezoid
	height = shadowArea * 2 / top;
	area = (top + bottom) *height / 2;
	cout<<"area of trapezoid is " << area<<endl;
	return 0;
}

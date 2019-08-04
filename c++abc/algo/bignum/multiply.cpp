/*
big integer multiply
*/

#include <iostream>
#include <cstring>
using namespace std;

// TODO: modify this function to output result with format "17,566,697,814"
// Any bugs if one number is 0?
void printResult(int data[], int len) {
    cout<<"length: "<<len<<endl<<"value:";
    for (int i = len - 1; i >= 0; i--) {
    	cout<<data[i];
	}
    cout<<endl;
}

int main(int argc, char ** argv) {
    char data1[100];
    char data2[100];
    int num1[100], num2[100], result[200];
    int len1 = 0, len2 = 0, lenret = 0;

    cout<<"input first integer:";
    cin>>data1; 
	len1 = strlen(data1);
    cout<<"input second integer:";
    cin>>data2; 
    
	len2 = strlen(data2);

    for (int i = 0; i < len1; i++) 
        num1[len1 - i - 1] = data1[i] - '0';
    
    for (int i = 0; i < len2; i++) 
        num2[len2 - i - 1] = data2[i] - 48;

    for (int i = 0; i < len1; i++) {
        int x = 0;
        for (int j = 0; j < len2; j++) {
            result[i + j] = num1[i] * num2[j] + x + result[i + j];
            x = result[i+j] / 10;
            result[i+j] = result[i+j] % 10;
        }
        if (x > 0) {
            result[i + len2] = x;
            lenret = i + len2 + 1;
        } else {
            lenret = i + len2;
        }
    }

    printResult(result, lenret);

}

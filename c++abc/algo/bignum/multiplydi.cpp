/*
It's interesting to multiply big integers.
big integers could be divided into multiple sections.
*/

#include <iostream>
#include <cstring>
using namespace std;

const int INTEGER_LEN = 100;
const int RESULT_LEN = 200;
int multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) {
        result[0] = '\0';
        return 0;
    }
    int len = len1 > len2 ? len1 : len2;
    int ret = 0;
    if (len <= 4) {
        //calculate directly
        int n1 = atoi(num1);
        int n2 = atoi(num2);
        ret = n1*n2;
        sprintf(result, "%d", ret);
        return strlen(result);
    }
    
    /* split integer into two sections
     num1 = a*10^n + b
     num2 = c*10^n + d
     num1 * num2 = (a*10^n + b) * (c*10^n + d) = ac*10^2n + (ad + bc)*10^n + bd
        = ac*10^2n + ((a-b)(d-c) + ac + bd)*10^n + bd
    */
    char a[50], b[50], c[50], d[50];
    char ac[100], bd[100], a1b1[100];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(ac, 0, sizeof(ac));
    memset(bd, 0, sizeof(bd));
    memset(a1b1, 0, sizeof(a1b1));
    int sec = len / 2;
    int lena = len1 - sec;
    if (lena > 0) {
        strncpy(a, num1, lena);
        cout<<"a->"<<a<<endl;
    }
    strcpy(b, num1 + lena);
	cout<<"b->"<<b<<endl; 

    int lenc = len2 - sec;
    if (lenc > 0) {
        strncpy(c, num2, lenc);
		cout<<"c->"<<c<<endl;
    }
    strcpy(d, num2 + lenc);
	cout<<"d->"<<d<<endl;
    
    if (lena > 0 && lenc > 0) {
        multiply(a, c, ac);
        multiply(a, d, a1b1);
    } else {
        ac[0] = '\0';
    }
    
	multiply(b, d, bd);
	//copy result into right sections
	int lenac = strlen(ac);
	int lenbd = strlen(bd);
	int lena1b1 = strlen(a1b1);
	strcpy(bd, result + RESULT_LEN - 1 - lenbd);
    return 0;
}

int main(int argc, char** argv) {
    char data1[INTEGER_LEN];
    char data2[INTEGER_LEN];
    char data3[RESULT_LEN];
    memset(data3, 0, sizeof(data3));
    cout<<"input the first integer:";
    cin>>data1;
    cout<<"input the second integer:";
    cin>>data2;
    int ret = multiply(data1, data2, data3);
    cout<<"result: "<<data3 - ret + RESULT_LEN - 1;
}

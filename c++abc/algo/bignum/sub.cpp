/*
big number calculation for sub
*/

#include <iostream>
#include <cstring>
using namespace std;

const int INTEGER_LEN = 100;
void sub(char num1[], char num2[]){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    bool neg = false;
    int n1[INTEGER_LEN], n2[INTEGER_LEN];
    char data[INTEGER_LEN];
    // memset int array is useles
    if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
        // num2 is bigger
        for (int i = 0; i < len2; i++) {
            n1[i] = num2[len2 - i -1] - '0';
        }
        for (int i = 0; i < len1; i++) {
            n2[i] = num1[len1 - i -1] - '0';
        }
        int x = len1; len1 = len2; len2 =x;
        neg = true;
    }
    for (int i = 0; i < len1; i++) {
        n1[i] = num1[len1 - i - 1] - '0';
    }
    for (int i = 0; i < len2; i++) {
        n2[i] = num2[len2 - i - 1] - '0';
    }
    for (int i = len2; i < len1; i++) {
    	n2[i] = 0;
	}
    int i = 0;
    for (; i < len1; i++) {
        if (n1[i] < n2[i]) {
            n1[i] += 10;
            n1[i+1]--;
        }
        //cout<<n1[i]<<"-"<<n2[i]<<endl; 
        data[i] = n1[i] - n2[i] + '0';
    }
    cout<<"result:";
    while(data[i - 1] == '0' && i >= 0) i--;
    for (int j = i - 1; j >= 0; j--) {
        cout<<data[j];
    }
    cout<<endl;
}

int main(int argc, char** argv) {
    char data1[INTEGER_LEN], data2[INTEGER_LEN], result[INTEGER_LEN];
    memset(result, 0, sizeof(result));
    cout<<"input first integer:";
    cin>>data1;
    cout<<"input second integer:";
    cin>>data2;
    sub(data1, data2);
}

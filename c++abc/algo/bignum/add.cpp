/*
big number calclulator for add
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool add(char num1[], int len1, char num2[], int len2, char result[]) {
    int len = len1 > len2 ? len1 : len2;
    bool f = false;
    int x = 0, ret = 0;
    result[len+1] = '\0';
    while (len1 > 0 && len2 > 0) {
        ret = num1[--len1] - '0' + num2[--len2] - '0' + x;
        //cout<<num1[len1]<<"+"<<num2[len2]<<endl;
        x = ret/10;
        result[len] = ret%10 + '0';
        //cout<<result[len]<<endl;
        len--;
    }
    
    //cout<<"len"<<len1<<"-"<<len2<<endl;
    if (x > 0 && len1 == 0 && len2 == 0) {
    	f = true;
	}
    result[len] = x + '0';
    if (len1 == 0) {
        // num1 is less than num2, need to process num2 here
        while (len2 > 0) {
        	if (x > 0) {
        		ret = num2[--len2] - '0' + x;
        		x = ret / 10;
        		result[len--] = ret % 10 + '0';
        		if (x > 0) {
        			f = true;
				}
				result[len] = x + '0';
			} else {
				result[len--] = num2[--len2];
				if (f) f = false;
			}
            //cout<<result[len]<<",len>"<<len<<endl;
        }
    }

    if (len2 == 0) {
        // num1 is less than num2, need to process num2 here
        while (len1 > 0) {
        	if (x > 0) {
        		ret = num1[--len1] - '0' + x;
        		x = ret / 10;
        		result[len--] = ret % 10 + '0';
        		if (x > 0) {
        			f = true;
				}
				result[len] = x + '0';
				//cout<<result[len]<<endl;
			} else {
				result[len] += num1[--len1];
				if (f) f = false;
			}
            //cout<<result[len]<<",len>"<<len<<endl;
        }
    }
    
    return f;
}

int main(int argc, char ** argv) {
    char data1[100], data2[100], result[101];
    memset(result, 0, sizeof(result));
    cout<<"input first integer:"<<endl;
    cin>>data1;
    cout<<"input second integer:"<<endl;
    cin>>data2;
    if (add(data1, strlen(data1), data2, strlen(data2), result))
	    cout<<"result > "<<result<<endl;
    else
        cout<<"result > "<<result+1<<endl;
    cout<<result[8]; 
}

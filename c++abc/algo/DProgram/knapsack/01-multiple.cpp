#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char**argv) {
    int quantity, amount;
    cin>>quantity>>amount;
    if (quantity <=0 || amount <= 0) return 0;

    // metrics[0] indicates weight
    // metrics[1] indicates values
    // metrics[2] indicates number
    int ** metrics = new int *[3];
    for (int i = 0; i < 3; i++) {
        metrics[i] = new int[quantity+1];
        memset(metrics[i], 0, (quantity+1)*sizeof(int));
    }

    int * m = new int[amount+1];
    memset(m, 0, (amount+1)*sizeof(int));
    for (int i = 1; i <= quantity; i++) 
        for (int j = amount; j >= 0; j--)
            for (int k = 0; k <= metrics[2][i]; k++) {
                if (j - k*metrics[1][i] > 0) break;
                if (m[j] < (m[j - k*metrics[0][i]] + k*metrics[1][i])) 
                    m[j] = m[j - k*metrics[0][i]] + k*metrics[1][i];
            }
    
    cout<<m[amount]<<endl;
    return 0;
}
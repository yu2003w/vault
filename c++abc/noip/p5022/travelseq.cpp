#include <iostream>
#include <string.h>
using namespace std;

/*
基环树，N个顶点，M条边，n>=m, 最多有一个环
删掉环中的一条边，图变成树，然后深度优先搜索
*/
void DFS(bool ** data, int i, int n, bool *visited) {
	visited[i] = true;
	cout<<i+1<<" ";
    for (int j = 0; j < n; j++) {
        if (data[i][j] && !visited[j]) {
            DFS(data, j, n, visited);
        }
    }   	
            
}
void DFSTraverse(bool **data, int n) {
    bool * visited = new bool[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    for (int i = 0; i < n; i++) { 
        if (!visited[i]) {
        	DFS(data, i, n, visited); 
        }
    }
}
int main(int argc, char ** argv) {
    int n, m;
    cin>>n>>m;
    if (m > n || m <=0 || n <= 0) {
        return 0;
    }

    bool ** data = new bool *[n];
    for (int i = 0; i < n; i++) {
    	data[i] = new bool[n];
    	memset(data[i], 0, n);
	}
         

    int * ret = new int[n];
    ret[0] = 1;
    int start = 0, end = 0;
    for (int i = 0; i < m; i++) {
        cin>>start>>end;
        //if (start > end) {
        	data[end-1][start-1] = true;
		//} else
        data[start-1][end-1] = true;
        
        
    }
    
    for (int i = 0; i <n; i++) {
    	for (int j = 0; j <n; j++) {
    		cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
    
    DFSTraverse(data, n);
    cout<<endl;
/*
    for (int i = 0; i <n; i++) {
        for (int j = i+1; j <n; j++) {
            if (data[i][j]) {
                
            }
        }
    }
    */
    return 0;
}

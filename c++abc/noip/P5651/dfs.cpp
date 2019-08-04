#include <iostream>
#include <string.h>
using namespace std;

/*
construct tree to store information of childs and weight for parent and child.
struct edge could store child and weight info.
array head[n] to store each node info and its value indicated first edge.
dis[n] to store weight from root to node
*/

typedef struct {
    // u is start vertex for an edge
    int u;
    // v is end vertex for an edge
    int v;
    int cost;
    int next;
} edge;

void dfsTree(int tree[], int dis[], edge eg[], int start, int total);
void dumpInfo(int head[], edge e[], int n, int m);

int main(int argc, char ** argv) {
    int n, m, q;
    // n vertex, m edges, q questions
    cin>>n>>m>>q;
    if (n <= 1 || m < 1 || q < 1) {
        return 0;
    }
    int * head = new int[n+1];
    memset(head, -1, sizeof(int)*(n+1));
    //edge array to store input info
    edge * e = new edge[2*m];
    memset(e, -1, sizeof(edge)*(2*m));

    int * dis = new int [n+1];
    memset(dis, -1, sizeof(int) * (n+1));
    dis[1] = 0;

    for (int i = 0; i < 2*m; i++) {
        cin>>e[i].u>>e[i].v>>e[i].cost;
        e[i].next = head[e[i].u];
        // below line cause failure, why???
        // head[e[i].u] = i++; 
        head[e[i].u] = i;

        // a little tricky here 
        e[++i].v = e[i].u;
        e[i].u = e[i-1].v;
        e[i].cost = e[i-1].cost;
        e[i].next = head[e[i].u];
        head[e[i].u] = i;
    }

    // dumpInfo(head, e, n, m);
    
    // traverse constructed tree with BFS or DFS
    dfsTree(head, dis, e, 1, n);
    int start, end, ret;
    for (int i = 0; i < q; i++) {
        cin>>start>>end;
        if (start < 1 || end < 1)
            continue;
        ret = dis[start] xor dis[end];
        cout<<ret<<endl;
    }
}

// start indicate tree node
void dfsTree(int tree[], int dis[], edge eg[], int start, int total) {
    static int count = 0;
    if (count == total) return;
    for (int j = tree[start]; j != -1; j = eg[j].next) {
        if (dis[eg[j].v] != -1) continue;
        dis[eg[j].v] = dis[start] xor eg[j].cost;
        count++;
        dfsTree(tree, dis, eg, eg[j].v, total);
    }
}

void dumpInfo(int head[], edge e[], int n, int m) {
    for (int i = 1; i <= n; i++) {
        cout<<"head["<<i<<"]->"<<head[i];
        if (head[i] != -1) {
            int next = head[i];
            while (next != -1) {
                cout<<" {"<<e[head[i]].u<<" "<<e[head[i]].v<<"}->"<<e[head[i]].cost<<",";
                next = e[next].next;
            }
        }
        cout<<endl;
    }
    
    // dump edge info
    cout<<"edge info"<<endl;
    for (int i = 0; i < m; i++) {
        cout<<i<<" "<<e[i].u<<" "<<e[i].v<<" "<<e[i].cost<<endl;
    }
}

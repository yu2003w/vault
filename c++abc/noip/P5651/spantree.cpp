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

void dfsTree(int tree[], int dis[], edge eg[], int start, int pa);
void dumpInfo(int head[], edge e[], int n, int m);

int findParent(int x, int pa[]) {
    return x == pa[x] ? x : pa[x] = findParent(pa[x], pa);
}

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
    edge * e1 = new edge[m];
    memset(e1, -1, sizeof(edge)*(m));

    edge * e2 = new edge[m*2];
    memset(e2, -1, sizeof(edge)*(2*m));

    int * dis = new int [n+1];
    memset(dis, 0, sizeof(int) * (n+1));

    // union find-set to remove duplicate edges, union find-set to indicate whether node visited or not.
    int * parent = new int[n+1];
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        cin>>e1[i].u>>e1[i].v>>e1[i].cost;
    }

    // construct spanning tree here, using head[1] as root node
    for (int i = 0, j = 0, k = 0; i < m && j < n - 1; i++) {
        int sp = findParent(e1[i].u, parent);
        int ep = findParent(e1[i].v, parent);
        if (sp == ep) {
            continue;
        }
        
        // union edge set, need to add edges twice
        parent[sp] = ep;
        e2[k].u = e1[i].u;
        e2[k].v = e1[i].v;
        e2[k].cost = e1[i].cost;
        e2[k].next = head[e1[i].u];
        head[e1[i].u] = k++;

        e2[k].u = e1[i].v;
        e2[k].v = e1[i].u;
        e2[k].cost = e1[i].cost;
        e2[k].next = head[e1[i].v];
        head[e1[i].v] = k++;

        j++;
    }

    // dumpInfo(head, e, n, m);
    
    // traverse constructed tree with BFS or DFS
    dfsTree(head, dis, e2, 1, 1);
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
void dfsTree(int tree[], int dis[], edge eg[], int start, int pa) {
    for (int j = tree[start]; j != -1; j = eg[j].next) {
        if (eg[j].v == pa) continue;
        dis[eg[j].v] = dis[start] xor eg[j].cost;
        dfsTree(tree, dis, eg, eg[j].v, start);
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

#include <iostream>
using namespace std;

enum GraphType {
    DirectGraph = 1,
    UndirectGraph
};

struct Weight {
    int w;
    Weight() {
        w = 0;
    }
    Weight(int weight) {
        w = weight;
    }
};

struct ArcNode {
    // next vertex pointed by this arc
    int adjvext; 
    ArcNode * next;
    Weight * info;
    ArcNode(int vex, ArcNode * n, int w) {
        adjvext = vex;
        next = n;
        info = new Weight(w);
    }
};

struct VertexType {
    char name[20];
    VertexType(int i) {
       sprintf(name, "v%d", i);
    }
};

struct VertexNode {
    VertexType * data;
    ArcNode * firstarc;
    
    void init(int i) {
        firstarc = NULL;
        data = new VertexType(i);
    }
};

struct ALGraph {
    VertexNode * adjList;
    int vexnum, arcnum;
    GraphType gtype;
    bool * visited;

    ALGraph(int vn, int an, GraphType t) {
        vexnum = vn;
        arcnum = an;
        gtype = t;
        visited = NULL;
    }

    void resetVisited() {
        for (int i = 0; i < vexnum; i++) {
            visited[i] = false;
        }
    }
};

ALGraph * createALGraph(int v, int a, GraphType t);
void * popArc(VertexNode * vnodes, int v);

// Depth first traverse graph 
void DFS(ALGraph *ag, int i);
void DFSTraverse(ALGraph *ag);

//TODO: Destroy graph
void deleteALGraph(ALGraph *);
// Broder first traverse graph
void BFSTraverse(ALGraph *ag);

int main(int argc, char** argv) {
    ALGraph * g = createALGraph(4, 4, DirectGraph);
    DFSTraverse(g);
}

/*
   Parameters:
      vnum --- vertex number
      anum --- arc number
      t --- Graph Type
 */
ALGraph * createALGraph(int vnum, int anum, GraphType t) {
    if (vnum <= 0) {
        return NULL;
    }
    ALGraph * alg = new ALGraph(vnum, anum, t);
    alg->adjList = new VertexNode[vnum];
    alg->visited = new bool[vnum];
    for (int i = 0; i < vnum; i++) {
        alg->adjList[i].init(i+1);
        // mark node i as unvisited
        alg->visited[i] = false;
    }
    popArc(alg->adjList, vnum);
    return alg;

}

/*
  hard code arc for demo graph
 */
void * popArc(VertexNode * vnodes, int vn) {
    vnodes[0].firstarc = new ArcNode(1, NULL, 0);
    ArcNode * tmp = new ArcNode(2, vnodes[0].firstarc, 0);
    vnodes[0].firstarc = tmp;

    vnodes[1].firstarc = NULL;

    vnodes[2].firstarc = new ArcNode(3, NULL, 0);
    vnodes[3].firstarc = new ArcNode(0, NULL, 0);
}

void DFS(ALGraph *ag, int i) {
    ag->visited[i] = true;
    VertexNode n = ag->adjList[i];
    cout<<n.data->name<<" ";
    
    for (ArcNode * arc = n.firstarc; arc != NULL; arc = arc->next) {
        if (!ag->visited[arc->adjvext]) {
            DFS(ag, arc->adjvext);
        }
    }
}

void DFSTraverse(ALGraph *ag) {
    if (ag != NULL && ag->adjList != NULL) {
        VertexNode * nodes = ag->adjList;
        ag->resetVisited();
        for (int i = 0; i < ag->vexnum; i++) {
            if (!ag->visited[i])
                DFS(ag, i);
        }
    }
}

void BFSTraverse(ALGraph *ag) {

}





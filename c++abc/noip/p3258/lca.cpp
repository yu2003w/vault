#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODE = 300001;
int s[MAX_NODE], dep[MAX_NODE], fa[MAX_NODE][30], cf[MAX_NODE];
vector<int> edge[MAX_NODE*2];
bool vis[MAX_NODE];

// 求出每个点的直接父亲
void dfs(int x, int pa) {
    fa[x][0] = pa;
    //cout<<"dfs "<<x<<" "<<fa[x][0]<<endl;
    dep[x] = dep[pa] + 1;
    cout<<"dfs dep["<<x<<"]="<<dep[x]<<endl;
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == pa)
        continue;
        dfs(edge[x][i], x);
    }
}

//使用数上倍增来求LCA
int lca(int x, int y) {
    if (dep[x] < dep[y]) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int diff = dep[x] - dep[y];
    for (int i = 30; i >= 0; i--)
        if (1<<i <=  diff) {
            diff -= 1<<i;
            x = fa[x][i];
        }
    //cout<<"lca "<<x<<" "<<y<<endl;
    if (x == y) return x;
    for (int i = 30; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if (x == y) return x;
    return fa[x][0];
}

void dfs_ans(int x)
{
    for(int i=0; i < edge[x].size(); i++)
    {
        cout<<edge[x][i]<<" "<<fa[x][0]<<endl;
        if(edge[x][i]==fa[x][0]) continue;
        dfs_ans(edge[x][i]);
        cout<<cf[x]<<" "<<cf[edge[x][i]]<<endl;
        cf[x] += cf[edge[x][i]];//求子树和
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>s[i];
    }

    for (int i = 1; i <= n; i++) {
        int start, end;
        cin>>start>>end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }

    dfs(s[1], 0);
    cout<<"direct parent:";
    for (int i = 1; i <=n; i++) {
        cout<<s[i]<<"->"<<fa[s[i]][0] <<" ";
    }
    cout<<endl;

    for (int j = 0; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            cout<<"fa["<<i<<"]["<<j<<"]="<<fa[i][j]<<",";
        }
        cout<<endl;
    }
    //开始倍增
    for (int j = 1; j <= 30; j++) 
        for (int i = 1; i <=n; i++) {
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    for (int j = 0; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            cout<<"fa["<<i<<"]["<<j<<"]="<<fa[i][j]<<",";
        }
        cout<<endl;
    }

    for (int i = 1; i < n; i++) {
        cf[s[i]]++; cf[s[i+1]]++;
        cout<<"lca("<<s[i]<<","<<s[i+1]<<")="<<lca(s[i], s[i+1])<<endl;
        cf[lca(s[i], s[i+1])] -= 2;
    }
cout<<"after double"<<endl;
    dfs_ans(s[1]);
cout<<"after dfs ans"<<endl;
    for(int i=2;i<=n;i++)
        cf[s[i]]--;

    for (int i = 1; i <=n; i++)
    cout<<cf[s[i]]<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool check=false;
set<int> adj[1005];
int color[1005];

void DFS1(int u){
    color[u]=1;
    for (int v:adj[u]){
        if (color[v]==0)
            DFS1(v);
        else if (color[v]==1)
            check=true;
    }
    color[u]=2;
}

bool DFS2(int u){
    color[u]=1;
    for (int v:adj[u]){
        if (color[v]==0){
            if (DFS2(v))
                return true;
        } else if (color[v]==1)
            return true;
    }
    color[u]=2;
    return false;
}

int main(){
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].insert(v);
    }
    DFS1(1);
    if (check) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    memset(color, 0, sizeof color);
    if (DFS2(1)) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    return 0;
}

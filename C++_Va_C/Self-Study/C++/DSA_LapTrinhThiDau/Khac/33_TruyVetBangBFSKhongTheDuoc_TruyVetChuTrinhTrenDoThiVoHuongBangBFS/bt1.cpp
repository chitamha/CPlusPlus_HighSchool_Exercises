#include <bits/stdc++.h>
#define ll long long
using namespace std;

//truy vet chu trinh tren do thi vo huong bang
//BFS khong duoc, nguyen nhan do parent[v]
//do cach luu cha cua 1 dinh nao do khac voi DFS

ll n, m, st, en;
vector<ll> adj[1005];
vector<bool> visited(1005, false);
vector<ll> parent(1005);
vector<ll> path;

bool BFS(ll i){
    queue<ll> q;
    q.push(i);
    visited[i]=true;
    while (!q.empty()){
        ll u=q.front();
        q.pop();
        for (ll v:adj[u]){
            if (!visited[v]){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
            else if (v!=parent[u]){
                en=v;
                st=parent[u];
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>> n>> m;
    for (ll i=1; i<=m; i++){
        ll u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool check=false;
    for (ll i=1; i<=n; i++){
        if (!visited[i]){
            if (BFS(i)){
                check=true;
                path.push_back(st);
                while (st!=en){
                    path.push_back(en);
                    en=parent[en];
                }
                path.push_back(st);
                reverse(path.begin(), path.end());
                break;
            }
        }
    }
    if (check){
        cout<< "YES"<< endl;
        for (int i:path) cout<< i<< " ";
    }
    else cout<< "NO"<< endl;
    return 0;
}

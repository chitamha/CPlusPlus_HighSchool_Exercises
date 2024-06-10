#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> A[1005];
bool visited[1005];

void DFS(int i){
    cout<< i<< " ";
    visited[i]=true;
    for (int x:A[i]){
        if (!visited[x]){
            DFS(x);
        }
    }
}
int main(){
    memset(visited, false, sizeof visited);
    cin>> n>> m>> s;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
        sort(A[i].begin(), A[i].end());
    DFS(s);
    return 0;
}

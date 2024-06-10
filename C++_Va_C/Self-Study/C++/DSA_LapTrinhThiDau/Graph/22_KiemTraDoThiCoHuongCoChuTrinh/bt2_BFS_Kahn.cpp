#include <bits/stdc++.h>
using namespace std;

int n, m, cnt=0;
bool check=false;
vector<int> adj[1005];
vector<int> degreein(1005, 0);

void Kahn(){
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (degreein[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;
        for (int v:adj[u]){
            degreein[v]--;
            if (degreein[v]==0){
                q.push(v);
            }
        }
    }
}

int main(){
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        degreein[v]++;
    }
    Kahn();
    if (cnt!=n) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    return 0;
}

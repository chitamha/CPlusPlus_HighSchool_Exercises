#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

int n, m, st, en, d[1005], before[1005];
pair<int, int> Located[1005];

double Dis(int x, int y){
    return sqrt(pow(1.0*(Located[x].fi-Located[y].fi), 2)+pow(1.0*(Located[x].se-Located[y].se), 2));
}

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[x]=0;
    pq.push({0, x});
    while (!pq.empty()){
        int u=pq.top().se, w=pq.top().fi;
        pq.pop();
        for (int v=1; v<=n; v++){
            if (Dis(u, v)<m*1.0 && d[v]>w+1){
                d[v]=w+1;
                before[v]=u;
                pq.push({w+1, v});
            }
        }
    }
}

int main(){
    freopen("DAO.INP", "r", stdin);
    freopen("DAO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> st>> en;
    for (int i=1; i<=n; i++){
        int x, y; cin>> x>> y;
        Located[i]={x, y};
        before[i]=i;
        d[i]=1000000000;
    }
    dijkstra(st);
    if (d[en]==1000000000) return cout<< -1, 0;
    cout<< d[en]-1<< endl;
    stack<int> tmp;
    while (before[en]!=st){
        en=before[en];
        tmp.push(en);
    }
    while (!tmp.empty()){
        cout<< tmp.top()<< " ";
        tmp.pop();
    }
    return 0;
}

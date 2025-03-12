/*
#include <bits/stdc++.h>
#define ll long long
#define llll pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll n, m, st, en, before[1000005], visited[1000005];
llll Located[1000005];

double Dis(ll x, ll y){
    return 1.0*(Located[x].fi-Located[y].fi)*(Located[x].fi-Located[y].fi)+1.0*(Located[x].se-Located[y].se)*(Located[x].se-Located[y].se);
}

void BFS(ll x){
    queue<ll> q;
    visited[x]=1;
    q.push(x);
    while (!q.empty()){
        ll u=q.front(); q.pop();
        for (ll v=1; v<=n; v++){
            if (!visited[v] && Dis(u, v)<pow(m, 2) && u!=v){
                before[v]=u;
                visited[v]=1;
                q.push(v);
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
    for (ll i=1; i<=n; i++){
        ll x, y; cin>> x>> y;
        Located[i]={x, y};
        before[i]=i;
    }
    BFS(st);
    if (before[en]==en) return cout<< -1, 0;
    stack<ll> tmp;
    while (before[en]!=st){
        en=before[en];
        tmp.push(en);
    }
    cout<< tmp.size()<< endl;
    while (!tmp.empty()){
        cout<< tmp.top()<< " ";
        tmp.pop();
    }
    return 0;
}
*/
#include <bits/stdc++.h>
#define ll long long
#define llll pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll n, m, st, en, d[1000005], before[1000005];
llll Located[1000005];

double Dis(ll x, ll y){
    return 1.0*(Located[x].fi-Located[y].fi)*(Located[x].fi-Located[y].fi)+1.0*(Located[x].se-Located[y].se)*(Located[x].se-Located[y].se);
}

void dijkstra(ll x){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[x]=0;
    pq.push({0, x});
    while (!pq.empty()){
        ll u=pq.top().se, w=pq.top().fi;
        pq.pop();
        for (ll v=1; v<=n; v++){
            if (Dis(u, v)<pow(m, 2) && d[v]>w+1 && u!=v){
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
    for (ll i=1; i<=n; i++){
        ll x, y; cin>> x>> y;
        Located[i]={x, y};
        before[i]=i;
        d[i]=1000000000;
    }
    dijkstra(st);
    if (before[en]==en) return cout<< -1, 0;
    cout<< d[en]-1<< endl;
    stack<ll> tmp;
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

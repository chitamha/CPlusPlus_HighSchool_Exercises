#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define Maxn 100005

const ll ma=-1000000;
vector<ll> gr[Maxn];
ll LM[3][Maxn], n, m, Affac[Maxn], Down[Maxn], Up[Maxn], Cha[Maxn], d;

void DfsD(ll u) {
    ll v;
    if (Affac[u]) Down[u] = 0;
    else Down[u] = ma;
    LM[1][u] = ma;
    LM[2][u] = ma;
    forr(i,0,gr[u].size()) {
        v = gr[u][i];
        if (v != Cha[u]) {
            Cha[v] = u;
            DfsD(v);
            if (Down[v] > LM[2][u]) {
                if (Down[v] > LM[1][u]) {
                    LM[2][u] = LM[1][u];
                    LM[1][u] = Down[v];
                }
                else LM[2][u] = Down[v];
                Down[u] = LM[1][u] + 1;
            }
        }
    }
}

void DfsU(ll v) {
    ll u;
    if (v == 1) {
        if (Affac[1]) Up[1] = 0;
        else Up[1] = ma;
    }
    else {
        u = Cha[v];
        Up[v] = Up[u] + 1;
        if ((Affac[v]) and (Up[v] < 0)) Up[v] = 0;
        if (LM[1][u] == Down[v]) Up[v] = max(Up[v], LM[2][u] + 2);
        else Up[v] = max(Up[v], LM[1][u] + 2);
    }
    forr(i,0,gr[v].size())
        if (gr[v][i] != Cha[v]) DfsU(gr[v][i]);
}

int main() {
    //freopen("book.inp","r",stdin);
    //freopen("book.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x, y;
    cin >> n >> m >> d;
    forr(i,1,n+1) Affac[i] = 0;
    forr(i,0,m) {
        cin >> x;
        Affac[x] = 1;
    }
    forr(i,0,n-1) {
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    Cha[1] = -1;
    DfsD(1);
    DfsU(1);
    ll ress = 0;
    forr(i,1,n+1)
        if ((Down[i] <= d) and (Up[i] <= d)) ress++;
    cout << ress;
    return 0;
}

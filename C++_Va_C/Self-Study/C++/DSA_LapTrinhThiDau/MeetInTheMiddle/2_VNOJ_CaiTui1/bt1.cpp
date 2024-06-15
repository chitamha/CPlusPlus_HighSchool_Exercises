#include <bits/stdc++.h>
#define maxn 1000006
#define ll long long
#define fi first
#define se second
using namespace std;

int n, m, ans=0;
vector<pair<int, int>> v, A, B;
vector<int> MaxB;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.se<b.se;
}

int Nhbcc(int x){
    int l=0, r=B.size()-1, mid;
    while (l<=r){
        mid=(l+r)/2;
        if (B[mid].se<=x) l=mid+1;
        else r=mid-1;
    }
    return l-1;
}

void Try(int siz, int en, vector<pair<int, int>> &Chua, int value, int weight){
    if (weight>m) return;
    if (siz>en){
        Chua.push_back({value, weight});
        return;
    }
    Try(siz+1, en, Chua, value+v[siz].fi, weight+v[siz].se);
    Try(siz+1, en, Chua, value, weight);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m; v.resize(n+10);
    for (int i=1; i<=n; i++) cin>> v[i].se>> v[i].fi;
    Try(1, n/2, A, 0, 0);
    Try(n/2+1, n, B, 0, 0);
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    /*
    for (auto p:A) cout<< p.fi<< " "<< p.se<< endl;
    cout<< endl;
    for (auto p:B) cout<< p.fi<< " "<< p.se<< endl;
    */
    MaxB.resize(B.size()); MaxB[0]=B[0].fi;
    for (int i=1; i<B.size(); i++) MaxB[i]=max(MaxB[i-1], B[i].fi);
    for (int i=0; i<A.size(); i++){
        int id=Nhbcc(m-A[i].se);
        if (id!=-1) ans=max(ans, A[i].fi+MaxB[id]);
    }
    cout<< ans;
    return 0;
}

#include <bits/stdc++.h>
#define maxn 1000006
#define ll long long
using namespace std;

int n; ll x, ans=0;
vector<int> v;
vector<ll> A, B;

void Try(int siz, int en, vector<ll> &Chua, ll sum){
    if (siz>en){
        Chua.push_back(sum);
        return;
    }
    Try(siz+1, en, Chua, sum+v[siz]);
    Try(siz+1, en, Chua, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> x; v.resize(n+10);
    for (int i=1; i<=n; i++) cin>> v[i];
    Try(1, n/2, A, 0);
    Try(n/2+1, n, B, 0);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    /*
    for (ll x:A) cout<< x<< " ";
    cout<< endl;
    for (ll x:B) cout<< x<< " ";
    */
    for (ll i:A){
        ans+=1ll*(upper_bound(B.begin(), B.end(), x-i)-lower_bound(B.begin(), B.end(), x-i));
    }
    cout<< ans;
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 200006
using namespace std;

ll n, S, ans=0;
vector<ll> A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> S;
    A.resize(n+5);
    for (int i=1; i<=n; i++) cin>> A[i];
    ll l1=1, l2=1, sum=0;
    while (l2<=n){
        sum+=A[l2];
        while (sum>S && l1<=l2){
            sum-=A[l1];
            l1++;
        }
        if (sum==S) ans++;
        //cout<< l1<< " "<< l2<< endl;
        l2++;
    }
    cout<< ans;
    return 0;
}

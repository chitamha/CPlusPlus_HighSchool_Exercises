#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, S, ans=-1e9;
ll W[1005];
ll V[1005];
ll X[1005];

void QL(ll i, ll ttv, ll ttw){
    for (ll j=0; j<=1; j++){
        X[i]=j;
        if (X[i]){
            ttv+=V[i];
            ttw+=W[i];
        }
        if (ttw>S || i>n) return;
        if (ttw<=S) ans=max(ans, ttv);
        QL(i+1, ttv, ttw);
    }
}

int main(){
    cin>> n>> S;
    for (ll i=1; i<=n; i++) cin>> W[i];
    for (ll i=1; i<=n; i++) cin>> V[i];
    QL(1, 0, 0);
    cout<< ans;
    return 0;
}

/*#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, S, ans=-1e9;
ll W[1005];
ll V[1005];
ll X[1005];

void QL(ll i, ll ttv, ll ttw){
    for (ll j=0; j<=1; j++){
        X[i]=j;
        if (ttw+j*W[i]>S || i>n) return;
        if (X[i]){
            ttv+=V[i];
            ttw+=W[i];
        }
        if (ttw<=S) ans=max(ans, ttv);
        QL(i+1, ttv, ttw);
    }
}

int main(){
    cin>> n>> S;
    for (ll i=1; i<=n; i++) cin>> W[i];
    for (ll i=1; i<=n; i++) cin>> V[i];
    QL(1, 0, 0);
    cout<< ans;
    return 0;
}*/

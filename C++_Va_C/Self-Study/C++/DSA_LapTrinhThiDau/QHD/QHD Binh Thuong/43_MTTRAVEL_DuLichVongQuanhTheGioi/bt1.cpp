#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, P, A[10005], F[10005], before[10005];
stack<ll> stop;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> P;
    for (ll i=1; i<=n; i++) cin>> A[i];
    for (ll i=1; i<=n; i++){
        F[i]=1e9;
        for (ll j=0; j<i; j++){
            if (F[i]>F[j]+(ll)(pow(A[i]-A[j]-P, 2))){
                before[i]=j;
                F[i]=F[j]+(ll)(pow(A[i]-A[j]-P, 2));
            }
        }
    }
    cout<< F[n]<< endl;
    ll tmp=n;
    while (tmp!=0){
        stop.push(tmp);
        tmp=before[tmp];
    }
    cout<< stop.size()<< endl;
    while (!stop.empty()){
        cout<< stop.top()<< " ";
        stop.pop();
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, m, k, Thia[20000005], Dua[20000005];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    freopen("GRUEL.INP", "r", stdin);
    freopen("GRUEL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    for (ll i=1; i<=k; i++){
        ll t, d, a;
        cin>> t>> d>> a;
        while (!pq.empty() && t>=pq.top()){
            n+=Thia[pq.top()]; m+=Dua[pq.top()];
            Thia[pq.top()]=0; Dua[pq.top()]=0;
            pq.pop();
        }
        //cout<< "n: "<< n<< "; m: "<< m<< "\n";
        if (a==0){
            if (n>=1){
                cout<< "Yes"<< "\n";
                n--;
                Thia[t+d]++;
                pq.push(t+d);
            } else cout<< "No"<< "\n";
        }
        else{
            if (n>=1 && m>=1){
                cout<< "Yes"<< "\n";
                n--; m--;
                Thia[t+d]++; Dua[t+d]++;
                pq.push(t+d);
            } else cout<< "No"<< "\n";
        }
    }
    //cout<< "n: "<< n<< "; m: "<< m<< "\n";
    return 0;
}

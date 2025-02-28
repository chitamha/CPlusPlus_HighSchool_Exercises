#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, t, F[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i=1; i<=1000000; i++){
        F[i]=F[i-1];
        if (i%2==1) F[i]+=i*i;
    }
    cin>> t;
    while (t--){
        cin>> n;
        cout<< F[n]<< "\n";
    }
    return 0;
}

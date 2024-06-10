#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
#define mod (long long) 1000000007
using namespace std;

int n, q, A[maxn], d[maxn];
map<int, int> cnt[maxn];
int mu[maxn];
ll ans=1;

void sanguoc(){
    for (int i=2; i<sqrt(maxn); i++){
        for (int j=i*i; j<maxn; j+=i){
            if (d[j]==0) d[j]=i;
        }
    }
    for (int i=2; i<maxn; i++) if (d[i]==0) d[i]=i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    sanguoc();
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        while (A[i]>1){
            int tmp=d[A[i]];
            while (A[i]%tmp==0) cnt[i][tmp]++, A[i]/=tmp;
            for (mu[tmp]; mu[tmp]<cnt[i][tmp]; mu[tmp]++){
                (ans*=tmp)%=mod;
            }
        }
    }
    while (q--){
        int i, x; cin>> i>> x;
        while (x>1){
            int tmp=d[x];
            while (x%tmp==0) cnt[i][tmp]++, x/=tmp;
            for (mu[tmp]; mu[tmp]<cnt[i][tmp]; mu[tmp]++){
                (ans*=tmp)%=mod;
            }
        }
        cout<< ans<< "\n";
    }
    return 0;
}

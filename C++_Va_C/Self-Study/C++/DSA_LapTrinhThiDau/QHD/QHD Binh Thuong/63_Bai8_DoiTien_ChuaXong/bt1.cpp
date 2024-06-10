#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, V, m[20], s[20];
vector<int> F;
vector<pair<int, int>> before;

int main(){
    cin>> n>> V;
    F.resize(V+5, 1e9); before.resize(V+5, {0, 0});
    for (int i=1; i<=n; i++) cin>> m[i];
    for (int i=1; i<=n; i++) cin>> s[i];
    F[0]=0;
    for (int i=1; i<=n; i++){
        for (int j=V; j>=m[i]; j--){
            for (int k=0; k<=s[i]; k++){
                if (j-k*m[i]>=0){
                    if (F[j]>F[j-k*m[i]]+k){
                        F[j]=F[j-k*m[i]]+k;
                        before[j]={i, k};
                    }
                } else break;
            }
        }
    }
    cout<< F[V]<< endl;
    int tmp=V;
    vector<int> Cnt(n+5, 0);
    while (tmp>0){
        cout<< tmp<< " "<< before[tmp].fi<< " "<< before[tmp].se<< endl;
        Cnt[before[tmp].fi]+=before[tmp].se;
        tmp-=m[before[tmp].fi]*before[tmp].se;
    }
    for (int i=1; i<=n; i++) cout<< Cnt[i]<< " ";
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, k, A[200005], F[200005][105], ans=0;
map<int, vector<int>> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        mp[A[i]].push_back(i);
        if (mp[A[i]-1].size()>=1){
            for (int j=0; j<mp[A[i]-1].size(); j++){
                int pos=mp[A[i]-1][j];
                for (int m=1; m<=k; m++){
                    if (pos==i-1){
                        F[i][m]=max(F[i][m], F[pos][m]+A[i]);
                    } else F[i][m]=max(F[i][m], F[pos][m-1]+A[i]);
                }
            }
        } else F[i][1]=A[i];
    }
    /*
    for (int j=1; j<=k; j++){
        for (int i=1; i<=n; i++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    for (int i=1; i<=n; i++) ans=max(ans, F[i][k]);
    cout<< ans;
    return 0;
}

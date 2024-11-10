#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int F[5][1000], ans=0;
    memset(F, 0, sizeof F);
    for (int i=1; i<=4; i++) F[i][1]=1;
    for (int i=2; i<=7; i++){
        for (int j=1; j<=4; j++){
            for (int k=1; k<=4; k++){
                if (j!=k) F[j][i]+=F[k][i-1];
            }
        }
    }
    for (int i=1; i<=4; i++) ans+=F[i][7]*3;
    cout<< ans;
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxT 155
using namespace std;

ll T, chiphithue, luong, chiphisathai;
ll SCN[105], C[105][155];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> T;
    cin>> chiphithue>> luong>> chiphisathai;
    for (int i=1; i<=T; i++) cin>> SCN[i];
    memset(C, 62, sizeof C);
    for (int i=0; i<=155; i++) C[0][i]=0;
    for (int i=0; i<=T; i++) C[i][0]=0;
    for (int i=1; i<=T; i++) for (int j=1; j<SCN[i]; j++) C[i][j]=0;
    for (int i=1; i<=T; i++){
        for (int j=SCN[i]; j<=155; j++){
            for (int k=SCN[i-1]; k<=155; k++){
                if (k>=j)
                    C[i][j]=min(C[i-1][k]+(k-j)*chiphisathai+j*luong, C[i][j]);
                else C[i][j]=min(C[i-1][k]+(j-k)*chiphithue+j*luong, C[i][j]);
            }
        }
    }
    ll ans=1e9;
    for (int j=SCN[T]; j<=155; j++){
        ans=min(ans, C[T][j]+j*chiphisathai);
    }
    cout<< ans;
    return 0;
}

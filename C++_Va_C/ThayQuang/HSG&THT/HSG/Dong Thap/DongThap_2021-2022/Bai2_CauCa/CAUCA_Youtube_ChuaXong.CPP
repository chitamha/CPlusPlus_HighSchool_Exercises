#include <bits/stdc++.h>
#define maxn 25
#define ll long long
using namespace std;

ll n, H, T[maxn], F[maxn], D[maxn];
ll dp[maxn][50*60+10], cc[maxn][50*60+10];
//Gọi dp[i][j] là số cá lớn nhất câu được
//khi xét đến hồ thứ i và thời gian j

void sub12(){
    //Câu chỉ 1 chỗ i, với thời gian j
    for (ll i=1; i<=n; i++){
        for (ll j=5; j<=H; j++){
            cc[i][j]=cc[i][j-5]+max(0ll, F[i]-D[i]*(j/5-1));
        }
    }
    if (n==1){
        cout<< cc[1][H];
        return;
    }
    ll ma=0;
    for (ll j=T[2]; j<=H; j++){
        ma=max(ma, cc[1][H-(j-T[2])-T[2]]+cc[2][j-T[2]]);
    }
    cout<< ma;
}

void sub3(){
    //Câu chỉ 1 chỗ i, với thời gian j
    for (ll i=1; i<=n; i++){
        for (ll j=5; j<=H; j++){
            cc[i][j]=cc[i][j-5]+max(0ll, F[i]-D[i]*(j/5-1));
        }
    }
    for (ll j=5; j<=H; j++) dp[1][j]=cc[1][j];
    ll movetime=T[2], ans=0;
    for (ll i=2; i<=n; i++){
        for (ll j=movetime; j<=H; j++){
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            for (ll k=0; k<=j-movetime; k++){
                dp[i][j]=max(dp[i][j], dp[i-1][j-k-T[i]]+cc[i][k]);
            }
            ans=max(ans, dp[i][j]);
        }
        movetime+=T[i+1];
    }
    cout<< ans;
    /*
    cout<< endl;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=H; j++) cout<< dp[i][j]<< " ";
        cout<< endl;
    }
    */
}

int main(){
    //freopen("CAUCA.INP", "r", stdin);
    //freopen("CAUCA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> H;
    H=H*60;
    for (ll i=2; i<=n; i++) cin>> T[i];
    for (ll i=1; i<=n; i++) cin>> F[i];
    for (ll i=1; i<=n; i++) cin>> D[i];
    if (n==1 || n==2) sub12();
    else sub3();
    return 0;
}

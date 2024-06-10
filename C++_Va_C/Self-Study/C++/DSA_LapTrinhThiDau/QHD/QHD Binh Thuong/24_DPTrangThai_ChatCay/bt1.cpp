#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

ll n, x[maxn], h[maxn], F[3][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin>> n;
    for (ll i=1; i<=n; i++){
        cin>> x[i]>> h[i];
    }
    //Quy hoạch động
    x[n+1]=1e18+10;
    F[0][1]=0;
    F[1][1]=1;
    F[2][1]=x[2]-x[1]>h[1] ? 1:0;
    for (ll i=2; i<=n; i++){
        //Đứng yên
        F[0][i]=max({F[0][i-1], F[1][i-1], F[2][i-1]});
        //Ngã sang trái
        ll tmp1=F[0][i-1];
        tmp1+=x[i]-x[i-1]>h[i] ? 1:0;
        ll tmp2=F[1][i-1];
        tmp2+=x[i]-x[i-1]>h[i] ? 1:0;
        ll tmp3=F[2][i-1];
        tmp3+=x[i]-x[i-1]>h[i]+h[i-1] ? 1:0;
        F[1][i]=max({tmp1, tmp2, tmp3});
        //Ngã sang phải
        ll tmp4=F[0][i-1], tmp5=F[1][i-1], tmp6=F[2][i-1];
        if (x[i+1]-x[i]>h[i])
            F[2][i]=max({tmp4, tmp5, tmp6})+1;
        else F[2][i]=max({tmp4, tmp5, tmp6});
    }
    cout<< max({F[0][n], F[1][n], F[2][n]});
    return 0;
}

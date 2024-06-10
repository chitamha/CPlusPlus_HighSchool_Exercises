#include <bits/stdc++.h>
#define ll long long
#define maxn 1006
using namespace std;

int n, m, t, A[maxn][maxn];
ll mi, preS[maxn][maxn];

void cnph(int x, int y, int u, int v, int left, int right){
    int l=left, r=right;
    while (l<=r){
        int mid=(l+r)/2;
        ll sum2=preS[u][v]-preS[u][y-1]-preS[mid-1][v]+preS[mid-1][y-1];
        ll sum1=preS[u][v]-preS[u][y-1]-preS[x-1][v]+preS[x-1][y-1]-sum2;
        mi=min(abs(sum1-sum2), mi);
        //cout<< mid<< " "<< sum1<< " "<< sum2<< " "<< mi<< "\n";
        if (sum2>sum1) l=mid+1;
        else r=mid-1;
    }
}

void cnpc(int x, int y, int u, int v, int left, int right){
    int l=left, r=right;
    while (l<=r){
        int mid=(l+r)/2;
        ll sum2=preS[u][v]-preS[u][mid-1]-preS[x-1][v]+preS[x-1][mid-1];
        ll sum1=preS[u][v]-preS[u][y-1]-preS[x-1][v]+preS[x-1][y-1]-sum2;
        mi=min(abs(sum1-sum2), mi);
        if (sum2>sum1) l=mid+1;
        else r=mid-1;
    }
}

void solution(int x, int y, int u, int v){
    cnph(x, y, u, v, x, u); cnpc(x, y, u, v, y, v);
    cout<< mi<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> t;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> A[i][j];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            preS[i][j]=preS[i][j-1]+preS[i-1][j]-preS[i-1][j-1]+A[i][j];
            //cout<< preS[i][j]<< " ";
        }
        //cout<< "\n";
    }
    while (t--){
        int x, y, u, v; mi=1e18;
        cin>> x>> y>> u>> v;
        solution(x, y, u, v);
    }
    return 0;
}

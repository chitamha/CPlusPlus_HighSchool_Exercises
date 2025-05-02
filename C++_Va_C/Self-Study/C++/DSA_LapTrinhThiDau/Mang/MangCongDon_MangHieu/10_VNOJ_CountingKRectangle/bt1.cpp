#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int m, n, k, A[405][405], F[30][405][405];

int Cal(int u, int v, int i, int j){
    int cnt=0;
    for (int tmp=1; tmp<=26; tmp++){
        if (F[tmp][i][j]-F[tmp][i][v-1]-F[tmp][u-1][j]+F[tmp][u-1][v-1]>=1) cnt++;
    }
    return cnt;
}

int solve(int siz){
    int ans=0;
    if (siz==0) return 0;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            int u=i, v=j;
            ans++;
            while (v+1<=n && Cal(i, j, u, v+1)<=siz) v++, ans++;
            u++;
            for (; u<=m; u++){
                while (v>j && Cal(i, j, u, v)>siz) v--;
                if (v>=j && Cal(i, j, u, v)<=siz) ans+=v-j+1;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> k;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            char c; cin>> c;
            A[i][j]=int(c)-64;
            //cout<< A[i][j]<< " ";
        }
        //cout<< endl;
    }
    for (int cnt=1; cnt<=26; cnt++){
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                F[cnt][i][j]=F[cnt][i-1][j]+F[cnt][i][j-1]-F[cnt][i-1][j-1];
                if (A[i][j]==cnt) F[cnt][i][j]++;
            }
        }
    }
    cout<< solve(k)-solve(k-1);
    return 0;
}

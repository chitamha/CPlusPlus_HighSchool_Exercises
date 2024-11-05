#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, k, ans=0;
char A[105][105];
map<int, int> F[105][105];

map<int, int> Plus(map<int, int> mp1, map<int, int> mp2){
    for (auto x:mp2){
        if (mp1.count(x.fi)!=0) mp1[x.fi]+=x.se;
        else mp1.insert({x.fi, x.se});
    }
    return mp1;
}

map<int, int> Sub(map<int, int> mp1, map<int, int> mp2){
    for (auto x:mp2){
        if (mp1.count(x.fi)!=0) mp1[x.fi]-=x.se;
        else mp1.insert({x.fi, -x.se});
    }
    return mp1;
}

int Dem(map<int, int> mp){
    int cnt=0;
    for (auto x:mp) if (x.se>0) cnt++;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> A[i][j];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            F[i][j]=Sub(Plus(F[i-1][j], F[i][j-1]), F[i-1][j-1]);
            F[i][j][A[i][j]]++;
            //for (auto x: F[i][j]) cout<< "("<< char(x.fi)<< "; "<< x.se<< ") ";
            //cout<< endl;
        }
    }
    //cout<< endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            for (int u=i; u<=n; u++){
                for (int v=j; v<=m; v++){
                    map<int, int> tmp=Plus(Sub(F[u][v], Plus(F[u][j-1], F[i-1][v])), F[i-1][j-1]);
                    int cnt=Dem(tmp);
                    if (cnt==k){
                        ans++;
                        //cout<< i<< " "<< j<< " "<< u<< " "<< v<< " "<< ans<< endl;
                        //for (auto x:tmp) cout<< "("<< char(x.fi)<< "; "<< x.se<< ") ";
                        //cout<< endl;
                    }
                    tmp.clear();
                }
            }
        }
    }
    cout<< ans;
    return 0;
}

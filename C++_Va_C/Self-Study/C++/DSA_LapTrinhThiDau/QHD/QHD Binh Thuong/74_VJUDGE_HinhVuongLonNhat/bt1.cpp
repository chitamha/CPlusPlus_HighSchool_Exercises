#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int m, n, ans=0;
vector<vector<int>> Left, Right, Down, Up, A;
//Noi tiep trang thai Left, Right...

int main(){
    freopen("MSQUARE.INP", "r", stdin);
    freopen("MSQUARE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n;
    Left.resize(m+5, vector<int>(n+5, 0)); Right.resize(m+5, vector<int>(n+5, 0));
    Down.resize(m+5, vector<int>(n+5, 0)); Up.resize(m+5, vector<int>(n+5, 0));
    A.resize(m+5, vector<int>(n+5, 0));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
            if (A[i][j]==1){
                Left[i][j]=Left[i][j-1]+1;
                Up[i][j]=Up[i-1][j]+1;
            }
        }
    }
    for (int i=m; i>=1; i--){
        for (int j=n; j>=1; j--){
            if (A[i][j]==1){
                Right[i][j]=Right[i][j+1]+1;
                Down[i][j]=Down[i+1][j]+1;
            }
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (A[i][j]==1){
                for (int k=min(Right[i][j], Down[i][j]); k>=ans; k--){
                    if (Left[i+k-1][j+k-1]>=k && Up[i+k-1][j+k-1]>=k){
                        ans=max(ans, k);
                        break;
                    }
                }
            }
        }
    }
    cout<< ans*ans;
    return 0;
}

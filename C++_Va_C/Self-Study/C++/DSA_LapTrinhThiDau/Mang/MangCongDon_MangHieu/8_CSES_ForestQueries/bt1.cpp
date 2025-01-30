#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, q, S[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c; cin>> c;
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
            if (c=='*') S[i][j]++;
        }
    }
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< S[i][j]<< " ";
        cout<< endl;
    }
    */
    for (int i=1; i<=q; i++){
        int x, y, a, b;
        cin>> a>> b>> x>> y;
        cout<< S[x][y]-S[x][b-1]-S[a-1][y]+S[a-1][b-1]<< endl;
    }
    return 0;
}

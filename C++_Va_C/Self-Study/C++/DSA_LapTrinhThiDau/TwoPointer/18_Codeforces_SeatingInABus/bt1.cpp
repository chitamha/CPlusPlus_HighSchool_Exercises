#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 200006
using namespace std;

int t, n, DD[maxn], check;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> t;
    while (t--){
        check=1;
        memset(DD, 0, sizeof DD);
        cin>> n;
        for (int i=1; i<=n; i++){
            int x; cin>> x;
            if (i!=1){
                if (DD[x-1] || DD[x+1]) DD[x]=1;
                else check=0;
            } else DD[x]=1;
        }
        if (check) cout<< "YES"<< "\n";
        else cout<< "NO"<< "\n";
    }
    return 0;
}

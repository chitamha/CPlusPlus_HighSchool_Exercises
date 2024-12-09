#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n; ll ans=0;
vector<int> Mod[25];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        Mod[x%23].push_back(i);
    }
    for (int i=0; i<=22; i++){
        for (int x:Mod[i])
            ans+=Mod[i].end()-upper_bound(Mod[i].begin(), Mod[i].end(), x+5);
    }
    /*
    for (int i=0; i<=22; i++){
        cout<< i<< ": ";
        for (int x:Mod[i]) cout<< x<< " ";
        cout<< endl;
    }
    */
    cout<< ans;
    return 0;
}

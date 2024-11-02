#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int t, n, cnt1, ans;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> t;
    while (t--){
        cin>> n;
        v.resize(n); cnt1=ans=0;
        for (int i=0; i<n; i++){
            cin>> v[i];
            cnt1+=v[i];
        }
        for (int i=0; i<n-cnt1; i++) if (v[i]) ans++;
        cout<< ans<< endl;
        v.clear();
    }
    return 0;
}

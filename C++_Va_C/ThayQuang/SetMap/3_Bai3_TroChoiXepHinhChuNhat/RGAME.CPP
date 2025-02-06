#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n, cnt=0;
map<int, int> mp;

int main(){
    freopen("RGAME.INP", "r", stdin);
    freopen("RGAME.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int k; cin>> k;
    while (k--){
        cin>> n;
        for (int i=1; i<=n; i++){
            int x; cin>> x;
            mp[x]++;
        }
        pair<int, int> st, nd;
        for (auto it=mp.rbegin(); it!=mp.rend(); it++){
            //cout<< (*it).fi<< " "<< (*it).se<< endl;
            if ((*it).se>=2){
                if (cnt==0){
                    nd=*it;
                    cnt++;
                }
                else if (cnt==1){
                    st=*it;
                    cnt++;
                    break;
                }
            }
        }
        if ((cnt==1 && nd.se<4) || cnt==0) cout<< -1<< endl;
        else {
            if (nd.se>=4) cout<< (ll)nd.fi*nd.fi<< endl;
            else cout<< (ll)st.fi*nd.fi<< endl;
        }
        cnt=0; mp.clear();
    }
    return 0;
}

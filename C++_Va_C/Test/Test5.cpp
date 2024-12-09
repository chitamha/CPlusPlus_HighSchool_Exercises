#include <bits/stdc++.h>
#define maxn 100005
#define fi first
#define se second
using namespace std;

int n, ans=0;
vector<pair<int, int>> A;
multiset<pair<int, int>> v;

int main(){
    //freopen("TOWER3.INP", "r", stdin);
    //freopen("TOWER1.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        int r, h; cin>> r>> h;
        A.push_back({r, h});
    }
    for (int i=A.size()-1; i>=0; i--){
        auto it=v.upper_bound(A[i]);
        if (it==v.end()) v.insert(A[i]);
        else{
            if ((*it).se==A[i].se){
                v.erase(it);
                v.insert(A[i]);
            } if ((*it).se>A[i].se){
                pair<int, int> tmp={(*it).fi, (*it).se-A[i].se};
                v.erase(it);
                v.insert(tmp);
                v.insert(A[i]);
            } else{
                int sum=0, cnt=0;
                auto en=it;
                while (sum<=A[i].se && en!=v.end()){
                    sum+=(*en).se;
                    en++; cnt++;
                }
                int check=1?0:en==v.end();
                for (int j=1; j<=cnt-1; j++) v.erase(it);
                if (check==0){
                    pair<int, int> tmp={(*it).fi, sum-A[i].se};
                    v.erase(it);
                    if (tmp.se>0) v.insert(tmp);
                }
                v.insert(A[i]);
            }
        }
    }
    //cout<< "Here"<< endl;
    //for (auto x:v) cout<< x.fi<< " "<< x.se<< endl;
    for (auto x:v) ans+=x.se;
    cout<< ans;
    return 0;
}

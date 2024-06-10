#include <bits/stdc++.h>
#define inf 1000006
using namespace std;

int n;
vector<vector<pair<int, int>>> v(inf);
int F[inf];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    for (int i=1; i<=n; i++){
        int st, en, cost;
        cin>> st>> en>> cost;
        v[en].push_back({st, cost});
    }
    for (int i=1; i<inf; i++){
        F[i]=F[i-1];
        for (int j=0; j<v[i].size(); j++){
            F[i]=max(F[v[i][j].first]+v[i][j].second, F[i]);
        }
    }
    cout<< *max_element(F, F+inf);
    return 0;
}

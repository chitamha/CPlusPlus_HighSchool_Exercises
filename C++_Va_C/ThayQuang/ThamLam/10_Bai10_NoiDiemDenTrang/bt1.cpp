#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A, B;
vector<pair<int, int>> P;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}

int main(){
    freopen("BWPOINTS.INP", "r", stdin);
    freopen("BWPOINTS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A.resize(n); B.resize(n);
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=0; i<n; i++) cin>> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i=0; i<n; i++){
        auto it1=upper_bound(B.begin(), B.end(), A[i]);
        auto it2=upper_bound(A.begin(), A.end(), B[i]);
        if (it1!=B.end())
            P.push_back({A[i], *it1});
        if (it2!=A.end())
            P.push_back({B[i], *it2});
    }
    if (P.size()!=0){
        sort(P.begin(), P.end(), cmp);
        int cnt=1, i=1, en=P[0].second;
        while (i<P.size()){
            if (P[i].first>en){
                cnt++;
                en=P[i].second;
            }
            i++;
        }
        cout<< cnt;
    } else cout<< 0;
    return 0;
}

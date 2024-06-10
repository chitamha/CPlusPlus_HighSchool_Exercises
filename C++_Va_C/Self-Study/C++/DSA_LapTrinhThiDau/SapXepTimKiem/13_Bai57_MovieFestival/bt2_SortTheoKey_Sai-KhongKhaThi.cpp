#include<bits/stdc++.h>
using namespace std;

int n, ans=1;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    cin>> n;
    for (int i=0; i<n; i++){
        int in, out;
        cin>> in>> out;
        v.push_back({in, out});
    }
    sort(v.begin(), v.end(), cmp);
    int end_time=v[0].second;
    for (int i=1; i<n; i++){
        if (end_time<=v[i].first){
            ans++;
            end_time=v[i].second;
        }
    }
    cout<< ans;
    return 0;
}

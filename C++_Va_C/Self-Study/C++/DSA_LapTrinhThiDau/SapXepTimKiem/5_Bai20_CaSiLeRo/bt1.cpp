#include <bits/stdc++.h>
using namespace std;

int n, ans=1;
vector<pair<long long, long long>> v;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    return a.second<b.second;
}

int main()
{
    cin>> n;
    for (int i=0; i<n; i++){
        long long in, out;
        cin>> in>> out;
        v.push_back({in, out});
    }
    sort(v.begin(), v.end(), cmp);
    int i=1;
    int endtime=v[0].second;
    while (i<n){
        if (v[i].first>=endtime){
            ans++;
            endtime=v[i].second;
        }
        i++;
    }
    cout<< ans;
    return 0;
}

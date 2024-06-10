#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    freopen("ELECTION.INP", "r", stdin);
    freopen("ELECTION.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    priority_queue<int> Q;
    for (int i=0; i<n; i++){
        int x; cin>> x;
        Q.push(x);
    }
    if (m==1) return cout<< 0, 0;
    int sum=0, i=0;
    while (sum<m && !Q.empty()){
        if (i!=0) sum-=1;
        int top=Q.top(); Q.pop();
        sum+=top;
        i++;
    }
    //cout<< sum<< " "<< i<< endl;
    if (sum>=m) cout<< i;
    else cout<< -1;
    return 0;
}

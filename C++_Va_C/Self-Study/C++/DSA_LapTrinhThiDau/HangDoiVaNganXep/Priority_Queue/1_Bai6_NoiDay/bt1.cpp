#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, ans=0;
    cin>> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=n; i++){
        int x;
        cin>> x;
        pq.push(x);
    }
    while (pq.size()!=1){
        int top1=pq.top(); pq.pop();
        int top2=pq.top(); pq.pop();
        ans+=top1+top2;
        pq.push(top1+top2);
    }
    cout<< ans;
    return 0;
}

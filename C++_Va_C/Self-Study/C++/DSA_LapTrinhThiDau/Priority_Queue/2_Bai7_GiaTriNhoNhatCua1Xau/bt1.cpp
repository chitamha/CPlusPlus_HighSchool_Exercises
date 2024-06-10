#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin>> t;
    for (int i=1; i<=t; i++){
        int k;
        long long ans=0;
        string s;
        map<char, int> mp;
        priority_queue<int> pq;
        cin>> k;
        cin.ignore();
        cin>> s;
        for (char i:s){
            mp[i]++;
        }
        for (auto i:mp){
            pq.push(i.second);
        }
        for (int i=1; i<=min(k, int(s.size())); i++){
            int top=pq.top(); pq.pop();
            top--;
            pq.push(top);
        }
        for (; !pq.empty();){
            int top=pq.top(); pq.pop();
            ans+=pow(top, 2);
        }
        cout<< ans<< endl;
    }
    return 0;
}

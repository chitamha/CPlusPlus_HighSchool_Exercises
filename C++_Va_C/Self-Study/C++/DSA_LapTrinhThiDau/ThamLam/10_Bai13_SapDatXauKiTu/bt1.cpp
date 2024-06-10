#include <bits/stdc++.h>
using namespace std;


int main(){
    map<char, int> mp;
    priority_queue<int> Q;
    string s; cin>> s;
    for (char c:s) mp[c]++;
    for (auto it:mp) Q.push(it.second);
    int ans=0;
    while (!Q.empty()){
        int top1=Q.top(); Q.pop();
        //cout<< top1<< " ";
        if (!Q.empty()){
            int top2=Q.top(); Q.pop();
            //cout<< top2<< " "<< top1-top2;
            Q.push(top1-top2);
        } else{
            if (top1<=1)
                ans=1;
        }
        //cout<< endl;
    }
    if (ans) cout<< "YES";
    else cout<< "NO";
    return 0;
}

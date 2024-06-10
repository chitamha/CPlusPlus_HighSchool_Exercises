#include <bits/stdc++.h>
#define ll long long
#define maxn 100006
using namespace std;

void process(string s){
    int n=s.size(); string ans="";
    s=" "+s;
    deque<char> even, odd;
    for (int i=1; i<=n; i++){
        if ((s[i]-'0')&1) odd.push_back(s[i]);
        else even.push_back(s[i]);
    }
    while (!even.empty() && !odd.empty()){
        if (even.front()>odd.front()){
            ans=ans+odd.front();
            odd.pop_front();
        } else{
            ans=ans+even.front();
            even.pop_front();
        }
    }
    while (!odd.empty()) ans=ans+odd.front(), odd.pop_front(); {}
    while (!even.empty()) ans=ans+even.front(), even.pop_front(); {}
    cout<< ans<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; string s;
    cin>> t;
    cin.ignore();
    while (t--){
        cin>> s;
        process(s);
    }
    return 0;
}
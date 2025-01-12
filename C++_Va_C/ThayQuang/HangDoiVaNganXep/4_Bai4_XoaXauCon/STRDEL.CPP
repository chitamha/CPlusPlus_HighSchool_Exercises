#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

string s;

int Sol(){
    stack<char> st;
    st.push(s[0]);
    for (int i=1; i<s.size(); i++){
        if (!st.empty() && ((st.top()=='A' && s[i]=='B') || (st.top()=='B' && s[i]=='B'))){
            st.pop();
        } else st.push(s[i]);
    }
    return st.size();
}

int main(){
    freopen("STRDEL.INP", "r", stdin);
    freopen("STRDEL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    cin.ignore();
    while (t--){
        cin>> s;
        cout<< Sol()<< endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
deque<char> dq, tmp;

int main(){
    freopen("KEYLOGGER.INP", "r", stdin);
    freopen("KEYLOGGER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    n=s.size();
    for (int i=0; i<n; i++){
        if (s[i]=='-' && !dq.empty()) dq.pop_back();
        else if (s[i]=='<' && !dq.empty()){
            tmp.push_front(dq.back());
            dq.pop_back();
        }
        else if (s[i]=='>' && !tmp.empty()){
            dq.push_back(tmp.front());
            tmp.pop_front();
        }
        else if (s[i]!='>' && s[i]!='<' && s[i]!='-') dq.push_back(s[i]);
    }
    for (char c:dq) cout<< c;
    for (char c:tmp) cout<< c;
    return 0;
}

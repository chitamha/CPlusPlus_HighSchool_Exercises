#include <bits/stdc++.h>
using namespace std;

int n;
string s, ans="";
deque<char> dq;

int main(){
    freopen("KEYLOGGER.INP", "r", stdin);
    freopen("KEYLOGGER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    getline(cin, s);
    n=s.size();
    deque<char> tmp;
    for (int i=0; i<n; i++){
        if (s[i]=='-') dq.pop_back();
        else if (s[i]=='<'){
            while (s[i]=='<'){
                if (!dq.empty()){
                    tmp.push_front(dq.back());
                    dq.pop_back();
                }
                i++;
            }
            i--;
        }
        else if (s[i]=='>'){
            while (s[i]=='>'){
                if (!tmp.empty()){
                    dq.push_back(tmp.front());
                    tmp.pop_front();
                }
                i++;
            }
            i--;
        }
        else dq.push_back(s[i]);
    }
    for (char c:dq) cout<< c;
    for (char c:tmp) cout<< c;
    return 0;
}

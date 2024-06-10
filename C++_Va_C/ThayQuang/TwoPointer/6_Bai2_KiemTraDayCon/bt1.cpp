#include <bits/stdc++.h>
using namespace std;
string s, t;
int main(){
    freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin, s);
    getline(cin, t);
    int l1=0, l2=0;
    while (l1<s.length() && l2<t.length()){
        if (s[l1]==t[l2]){
            l1++; l2++;
        } else{
            l2++;
        }
    }
    if (l1<s.length()) cout<< "NO";
    else cout<< "YES";
    return 0;
}

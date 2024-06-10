#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string s;

int main(){
    cin>> s;
    s='@'+s;
    ll i=s.size()-2;
    while (i>=1 && s[i]>=s[i+1]){
        i--;
    }
    if (i==0){
        cout<< 0;
        return 0;
    }
    else{
        sort(s.begin()+i+1, s.end());
        auto it=upper_bound(s.begin()+i+1, s.end(), s[i]);
        swap(*it, s[i]);
    }
    for (int i=1; i<=s.size()-1; i++) cout<< s[i];
    return 0;
}

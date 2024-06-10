#include <bits/stdc++.h>
using namespace std;

string s;
map<int, int> mp;
int ans=1e9;

bool check(map<int, int> mp){
    for (auto i:mp){
        if (i.second==0)
            return false;
    }
    return true;
}

int main(){
    cin>> s;
    for (char i:s) mp[i]=0;
    s='@'+s;
    int l=1, r=0;
    for (l; l<=s.size()-1; l++){
        while (!check(mp) && r<=s.size()-1){
            r++;
            mp[s[r]]++;
        }
        if (check(mp)) ans=min(ans, r-l+1);
        mp[s[l]]--;
    }
    cout<< ans;
    return 0;
}

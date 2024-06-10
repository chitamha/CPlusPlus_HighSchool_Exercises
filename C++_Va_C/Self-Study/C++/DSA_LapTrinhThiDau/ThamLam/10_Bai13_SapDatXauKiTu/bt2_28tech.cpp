#include <bits/stdc++.h>
using namespace std;

void solution(string s, int Max){
    if (Max>(s.size()+1)/2) cout<< "NO";
    else cout<< "YES";
}

int main(){
    map<char, int> mp;
    string s; int Max=0;
    cin>> s;
    for (char c:s) mp[c]++;
    for (auto it:mp) Max=max(Max, it.second);
    solution(s, Max);
    return 0;
}

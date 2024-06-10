#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, int>> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string ten;
    while(cin>> ten){
        int stc, diem;
        cin>> stc>> diem;
        mp[ten].first+=stc;
        mp[ten].second+=diem*stc;
    }
    for (auto it=mp.rbegin(); it!=mp.rend(); it++){
        cout<< (*it).first<< " : "<< fixed<< setprecision(2)<< 1.0*(*it).second.second/(*it).second.first<< endl;
    }
    return 0;
}

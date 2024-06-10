#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main(){
    char c;
    int max_value=0, min_value=INT_MAX;
    while (cin>> c){
        mp[c]++;
        max_value=max(max_value, mp[c]);
        min_value=min(min_value, mp[c]);
    }
    for (auto it=mp.begin(); it!=mp.end(); it++){
        if ((*it).second==max_value){
            cout<< (*it).first<< " "<< (*it).second<< endl;
            break;
        }
    }
    for (auto it=mp.rbegin(); it!=mp.rend(); it++){
        if ((*it).second==min_value){
            cout<< (*it).first<< " "<< (*it).second<< endl;
            break;
        }
    }
    cout<< mp.size();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

map<string, multiset<string>> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>> n;
    cin.ignore();
    for (int i=0; i<n; i++){
        string xau, str1, str2;
        getline(cin, xau);
        int pos=xau.find('-');
        str1=xau.substr(0, pos-1);
        str2=xau.substr(pos+2);
        mp[str1].insert(str2);
        mp[str2].insert(str1);
    }
    for (auto i:mp){
        cout<< i.first<< " : ";
        for (auto j:i.second){
            cout<< j;
            if (j!=*(i.second.rbegin())){
                cout<< ", ";
            }
        }
        cout<< endl;
    }
}

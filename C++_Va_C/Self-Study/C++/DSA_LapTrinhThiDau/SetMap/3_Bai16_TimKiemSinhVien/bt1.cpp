#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>> n;
    map<string, string> mp;
    for (int i=0; i<n; i++){
        string tam1, tam2;
        cin>> tam1;
        cin.ignore();
        getline(cin, tam2);
        mp[tam1]=tam2;
    }
    int q;
    cin>> q;
    string masv;
    while (q--){
        cin>> masv;
        if (mp.find(masv)!=mp.end()){
            cout<< mp[masv]<< endl;
        } else cout<< "NOT FOUND"<< endl;
    }
    return 0;
}

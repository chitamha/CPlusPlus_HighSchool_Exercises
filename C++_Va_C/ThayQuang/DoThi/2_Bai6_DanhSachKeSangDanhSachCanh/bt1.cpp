#include <bits/stdc++.h>
using namespace std;

int n;
set<int> adj[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n;
    cin.ignore();
    for (int i=1; i<=n; i++){
        string str;
        getline(cin, str);
        stringstream ss(str);
        string so;
        while(ss>> so){
            int x=stoi(so);
            adj[i].insert(x);
            adj[x].insert(i);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j:adj[i])
            if (i<j) cout<< i<< " "<< j<< endl;
    }
    return 0;
}

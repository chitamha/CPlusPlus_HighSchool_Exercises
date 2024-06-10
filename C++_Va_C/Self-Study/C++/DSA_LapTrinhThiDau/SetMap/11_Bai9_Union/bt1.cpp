#include <bits/stdc++.h>
using namespace std;
set<int> se;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>> n>> m;
    for (int i=0; i<n; i++){
        int tam; cin>> tam;
        se.insert(tam);
    }
    for (int i=0; i<m; i++){
        int tam; cin>> tam;
        se.insert(tam);
    }
    for (auto it=se.rbegin(); it!=se.rend(); it++){
        cout<< *it<< " ";
    }
    return 0;
}

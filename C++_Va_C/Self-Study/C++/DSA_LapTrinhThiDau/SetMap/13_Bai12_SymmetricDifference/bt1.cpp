#include <bits/stdc++.h>
using namespace std;
set<int> se1, se2, se;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>> n>> m;
    for (int i=0; i<n; i++){
        int tam; cin>> tam;
        se1.insert(tam);
    }
    for (int i=0; i<m; i++){
        int tam; cin>> tam;
        se2.insert(tam);
    }
    for (auto it=se1.begin(); it!=se1.end(); it++){
        if (!se2.count(*it)) se.insert(*it);
    }
    for (auto it=se2.begin(); it!=se2.end(); it++){
        if (!se1.count(*it)) se.insert(*it);
    }
    for (auto it=se.begin(); it!=se.end(); it++){
        cout<< *it<< " ";
    }
    return 0;
}

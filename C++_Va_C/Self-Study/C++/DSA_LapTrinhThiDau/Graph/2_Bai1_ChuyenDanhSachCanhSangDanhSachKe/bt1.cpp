#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    vector<vector<int>> v(n+1);
    while (m--){
        int u1, v1;
        cin>> u1>> v1;
        v[u1].push_back(v1);
        v[v1].push_back(u1);
    }
    for (int i=1; i<=n; i++){
        cout<< i<< " : ";
        sort(v[i].begin(), v[i].end());
        for (int x:v[i]) cout<< x<< " ";
        cout<< endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    vector<set<int>> v(n+1);
    while (m--){
        int u1, v1;
        cin>> u1>> v1;
        v[u1].insert(v1);
        v[v1].insert(u1);
    }
    for (int i=1; i<=n; i++){
        cout<< i<< " : ";
        for (int x:v[i]) cout<< x<< " ";
        cout<< endl;
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> A[1005];
int main(){
    int n, m;
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u1, v1;
        cin>> u1>> v1;
        A[u1].push_back(v1);
    }
    for (int i=1; i<=n; i++){
        cout<< i<< " : ";
        sort(A[i].begin(), A[i].end());
        for (int x:A[i]){
            cout<< x<< " ";
        }
        cout<< endl;
    }
    return 0;
}

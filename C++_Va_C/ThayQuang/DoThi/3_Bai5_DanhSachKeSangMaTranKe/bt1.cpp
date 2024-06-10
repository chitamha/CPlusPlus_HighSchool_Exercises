#include <bits/stdc++.h>
using namespace std;

int n;
set<int> adj[1005];
int A[1005][1005];

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
            A[i][x]=1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            cout<< A[i][j]<< " ";
        cout<< endl;
    }
    return 0;
}

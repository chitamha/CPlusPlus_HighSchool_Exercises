#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> A(55, -1), tmp(55, -1);

int main(){
    freopen("XEPHANG.INP", "r", stdin);
    freopen("XEPHANG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> t;
    for (int i=1; i<=n; i++){
        char c; cin>> c;
        if (c=='G') A[i]=0;
        else A[i]=1;
    }
    int cnt=0;
    while (true){
        bool check=false;
        for (int i=1; i<=n-1; i++){
            if (A[i]>A[i+1]){
                check=true;
                swap(A[i], A[i+1]);
                i++;
            }
        }
        if (check){
            cnt++;
            if (cnt==t) tmp=A;
        }
        else break;
    }
    if (t>cnt){
        for (int i=1; i<=n; i++){
            if (A[i]==1) cout<< 'B';
            else cout<< 'G';
        }
    } else{
        for (int i=1; i<=n; i++){
            if (tmp[i]==1) cout<< 'B';
            else cout<< 'G';
        }
    }
    cout<< endl<< cnt;
    return 0;
}

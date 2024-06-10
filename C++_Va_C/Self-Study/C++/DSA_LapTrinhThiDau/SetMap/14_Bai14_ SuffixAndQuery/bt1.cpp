#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>> n;
    int A[n];
    int F[n];
    set<int> se;
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=n-1; i>=0; i--){
        se.insert(A[i]);
        F[i]=se.size();
    }
    int t, l;
    cin>> t;
    while (t--){
        cin>> l;
        cout<< F[l]<< endl;
    }
    return 0;
}

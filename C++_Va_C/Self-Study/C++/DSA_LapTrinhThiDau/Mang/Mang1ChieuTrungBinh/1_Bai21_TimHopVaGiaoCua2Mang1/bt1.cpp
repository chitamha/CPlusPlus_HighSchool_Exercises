#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n+1], B[m+1];
    map<int, int> mp;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        mp[A[i]]++;
    }
    for (int j=1; j<=m; j++){
        cin>> B[j];
        mp[B[j]]++;
    }
    for (auto x:mp){
        if (x.second!=1){
            cout<< x.first<< " ";
        }
    }
    cout<< endl;
    int i=1, j=1;
    sort(A+1, A+n+1);
    sort(B+1, B+m+1);
    while (i<=n && j<=m){
        if (A[i]<B[j]){
            cout<< A[i]<< " ";
            i++;
        } else if (A[i]>B[j]){
            cout<< B[j]<< " ";
            j++;
        } else i++;
    }
    while (i<=n){
        cout<< A[i]<< " ";
        i++;
    }
    while (j<=m){
        cout<< B[j]<< " ";
        j++;
    }
    return 0;
}

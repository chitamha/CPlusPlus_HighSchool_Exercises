#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n+1], B[m+1];
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    for (int j=1; j<=m; j++){
        cin>> B[j];
    }
    int i=1, j=1;
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
    i=1; j=1;
    cout<< endl;
    while (i<=n && j<=m){
        if (A[i]==B[j]){
            cout<< A[i]<< " ";
            i++;
            j++;
        } else if (A[i]>B[j]){
            j++;
        } else i++;
    }
    return 0;
}

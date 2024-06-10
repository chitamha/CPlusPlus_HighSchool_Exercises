#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>> n;
    int A[n];
    set<int> DD;
    for (int i=0; i<n; i++){
        cin>> A[i];
        DD.insert(A[i]);
    }
    for (int i=0; i<n; i++){
        if (DD.find(A[i])!=DD.end()){
            cout<< A[i]<< " ";
            DD.erase(A[i]);
        }
    }
    return 0;
}

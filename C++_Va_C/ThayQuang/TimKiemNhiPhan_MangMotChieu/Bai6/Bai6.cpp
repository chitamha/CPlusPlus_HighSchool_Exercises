#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    cin>> n>> x;
    /*cach 1
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    sort(A, A+n);
    int dau=lower_bound(A, A+n, x)-A;
    int cuoi=upper_bound(A, A+n, x)-A-1;
    cout<< cuoi-dau+1;
    */
    //cach 2
    multiset<int> A;
    for (int i=0; i<n; i++){
        int tam;
        cin>> tam;
        A.insert(tam);
    }
    cout<< A.count(x);
    return 0;
}

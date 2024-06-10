#include <iostream>
#include <algorithm>
using namespace std;
int A[1000];
int q, x, n;
int binarysearch(int x){
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (A[mid]==x) return 1;
        else if (A[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return 0;
}
int main(){
    freopen("TIMKIEM.INP", "r", stdin);
    freopen("TIMKIEM.OUT", "w", stdout);
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    sort(A, A+n);
    cin>> q;
    int B[q];
    for (int i=0; i<q; i++){
        cin>> x;
        B[i]=x;
    }
    for (int i=0; i<q; i++){
        if (binarysearch(B[i]))
            cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}

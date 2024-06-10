#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int x, int A[], int n){
    int k=-10;
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (A[mid]==x){
            k=mid;
            r=mid-1;
        }
        else if (A[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return k;
}
int main(){
    int n, x;
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    cin>> n>> x;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    sort(A, A+n);
    int dau=binarysearch(x, A, n);
    int cuoi=dau;
    for (int i=dau+1; i<n; i++){
        if (A[i]!=x){
            break;
        }
        ++cuoi;
    }
    if (dau!=-10) cout<< binarysearch(x, A, n)<< " "<< cuoi;
    else cout<< 0;
    return 0;
}

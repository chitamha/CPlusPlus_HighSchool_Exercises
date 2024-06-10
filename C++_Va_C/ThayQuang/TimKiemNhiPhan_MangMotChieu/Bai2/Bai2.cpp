#include <bits/stdc++.h>
using namespace std;
int binarysearch(int x, int A[], int n){
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (A[mid]==x) return 0;
        else if (A[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return 1;
}
int main(){
    int n, m;
    ifstream fin("LIETKE.INP");
    ofstream fout("LIETKE.OUT");
    fin>> n>> m;
    int A[n], B[m];
    for (int i=0; i<n; i++){
        fin>> A[i];
    }
    for (int i=0; i<m; i++){
        fin>> B[i];
    }
    sort(B, B+m);
    int check=0;
    for (int i=0; i<n; i++){
        if (binarysearch(A[i], B, m)){
            fout<< A[i]<< " ";
            check=1;
        }
    }
    if (!check) fout<< "NOT FOUND";
    fin.close();
    fout.close();
    return 0;
}

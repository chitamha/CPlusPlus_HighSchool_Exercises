#include <bits/stdc++.h>
#define MAXN 1000006
using namespace std;

vector<int> socach(MAXN, -1);

int soCach(int A[], int x, int n){
    if (binary_search(A, A+n, x)){
        return socach[x];
    }
    for (int i=0; i<n; i++){
        if (socach[x]!=1 && x-A[i]>0){
            if (i==0)
                socach[x]=soCach(A, x-A[i], n)+1;
            else socach[x]=min(socach[x], soCach(A, x-A[i], n)+1);
        }
    }
    return socach[x];
}
int main(){
    int n, x; cin>> n>> x;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
        socach[A[i]]=1;
    }
    if (soCach(A, x, n)!=-1){
        cout<< soCach(A, x, n);
    } else cout<< -1;
}

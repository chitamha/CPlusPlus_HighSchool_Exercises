#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n], B[m];
    int F[m];
    memset(F, 0, sizeof F);
    for (int i=0; i<n; i++) cin>> A[i];
    for (int j=0; j<m; j++) cin>> B[j];
    int l1=0, l2=0;
    while (l1<n && l2<m){
        if (A[l1]==B[l2]){
            F[l2]++;
            l1++;
        } else if (A[l1]<B[l2]){
            l1++;
        } else{
            if (B[l2]==B[l2+1])
                F[l2+1]=F[l2];
            l2++;
        }
    }
    while (l2+1<m){
        if (B[l2]==B[l2+1]){
            F[l2+1]=F[l2];
            l2++;
        } else l2=m;

    }
    int tong=0;
    for (int i=0; i<m; i++){
        tong+=F[i];
    }
    cout<< tong;
    return 0;
}

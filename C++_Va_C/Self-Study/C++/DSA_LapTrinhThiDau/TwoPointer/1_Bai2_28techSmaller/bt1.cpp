#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n+1], B[m+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++) cin>> B[i];
    int l1=1, l2=1;
    int cnt=0;
    while (l1<=n && l2<=m){
        if (A[l1]>=B[l2]){
            cout<< cnt<< " ";
            l2++;
        } else{
            cnt++;
            l1++;
        }
    }
    while (l2<=m){
        cout<< n<< " ";
        l2++;
    }
    return 0;
}

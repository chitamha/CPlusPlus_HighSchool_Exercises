#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int A[maxn], n;

int main(){
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int maxx=A[1]-A[0];
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            maxx=max(A[i]-A[j], maxx);
        }
    }
    cout<< maxx;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n, k, tc, t, A[100001];

int gtnn(int i, int j, int k, long long A[]){
    long long nn=abs(A[i]-A[j]);
    for (int h=0; h<k; h++){
        nn=min(nn, abs(A[i]-A[j+h]));
    }
    return nn;
}

int main(){
    cin>> tc;
    while (tc--){
        cin>> n>> k>> t;
        for (int i=0; i<n; i++) cin>> A[i];
        int r=k-1;
        int Min, check=0;
        for (int i=0; i<=n-k; i++){
            Min=gtnn(r+1, i, k, A);
            if (Min<=t){
                cout<< "YES"<< endl;
                check=1;
                break;
            }
            r++;
        }
        if (!check) cout<< "NO"<< endl;
    }
    return 0;
}

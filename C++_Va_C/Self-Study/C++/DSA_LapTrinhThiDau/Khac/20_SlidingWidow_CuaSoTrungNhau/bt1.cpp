#include <bits/stdc++.h>
#define maxn 100001
using namespace std;

long long A[maxn];
int t, n, k;

int check(int i, int k, long long A[]){
    for (int j=0; j<k-1; j++){
        for (int h=j+1; h<k; h++){
            if (A[i+j]==A[i+h]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin>> t;
    while (t--){
        cin>> n>> k;
        for (int i=1; i<=n; i++){
            cin>> A[i];
        }
        int kt=check(1, k, A);
        if (kt){
            cout<< "YES"<< endl;
        } else{
            for (int i=2; i<=n; i++){
                if (A[i+k-1]!=A[i-1]){
                    kt=check(i, k, A);
                }
                if (kt){
                    cout<< "YES"<< endl;
                    break;
                }
            }
            if (!kt) cout<< "NO"<< endl;
        }
    }
    return 0;
}

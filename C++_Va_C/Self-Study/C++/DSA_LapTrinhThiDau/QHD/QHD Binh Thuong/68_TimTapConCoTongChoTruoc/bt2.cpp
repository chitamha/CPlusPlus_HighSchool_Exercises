#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int A[maxn];
int F[maxn];
int t, n, s;

int main(){
    cin>> t;
    while (t--){
        cin>> n>> s;
        for (int i=1; i<=n; i++) cin>> A[i];
        for (int i=1; i<=s; i++){
            F[i]=0;
        }
        F[0]=1;
        for (int i=1; i<=n; i++){
            for (int j=s; j>=1; j--){
                if (j-A[i]>=0)
                    F[j]=F[j] || F[j-A[i]];
            }
        }
        if (F[s]) cout<< "YES\n";
        else cout<< "NO\n";
    }
    return 0;
}

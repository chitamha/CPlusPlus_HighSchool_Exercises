#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, x;
vector<int> C(maxn), F(maxn, 1e9);

int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> C[i];
    }
    F[0]=0;
    for (int i=1; i<=x; i++){
        for (int j=0; j<n; j++){
            if (i-C[j]>=0){
                F[i]=min(F[i], F[i-C[j]]+1);
            }
        }
    }
    if (F[x]!=1e9) cout<< F[x];
    else cout<< -1;
    return 0;
}

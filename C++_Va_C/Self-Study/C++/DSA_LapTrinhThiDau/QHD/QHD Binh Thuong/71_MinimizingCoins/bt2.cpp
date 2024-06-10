#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, x, f[maxn], a[maxn];

int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> a[i];
    }
    f[0]=0;
    for (int s=1; s<=x; s++){
        f[s]=1e6+6;
        for (int i=0; i<n; i++){
            if (s-a[i]>=0){
                f[s]=min(f[s], f[s-a[i]]+1);
            }
        }
    }
    if (f[x]==1e6+6) cout<< -1;
    else cout<< f[x];
}

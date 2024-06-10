#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1000006
using namespace std;
int f[maxn];
int main(){
    int n=1;
    while (n>=0){
        memset(f, 0, sizeof f);
        int n; cin>> n;
        f[0]=1;
        for (int i=1; i<=n; i++){
            for (int j=max(0, i-6); j<=i-1; j++){
                (f[i]+=f[j])%=MOD;
            }
        }
        cout<< "So cach tao ra "<< n<< " la: "<< f[n]<< endl;
    }
}

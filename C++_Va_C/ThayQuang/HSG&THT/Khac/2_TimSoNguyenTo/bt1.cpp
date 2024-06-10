#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;

long long m, n, k;
vector<long long> prime(maxn, 1);
void sang(){
    prime[0]=prime[1]=0;
    for (int i=1; i<=sqrt(maxn); i++){
        if (prime[i]){
            for (int j=i*i; j<=maxn; j+=i){
                prime[j]=0;
            }
        }
    }
}
bool solve(int n, int k){
    int tong=0;
    while (n!=0){
        tong+=n%10;
        n/=10;
    }
    if (tong%k==0) return 1;
    else return 0;
}

int main(){
    sang();
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    cin>> m>> n>> k;
    int dem=0;
    for (int i=m; i<=n; i++){
        if (prime[i] && solve(i, k)){
            dem++;
        }
    }
    cout<< dem;
    return 0;
}

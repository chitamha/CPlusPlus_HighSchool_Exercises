#include <iostream>
#include <math.h>
using namespace std;
int NT[100001];
long long n;
void sangSo(long long n){
    for (int i=0; i<=n; i++){
        NT[i]=1;
    }
    NT[0]=NT[1]=0;
    for (int i=2; i<=sqrt(n); i++){
        if (NT[i]==1){
            for (int j=i*i; j<=n; j+=i){
                NT[j]=0;
            }
        }
    }
}
int UNTNN(int k, int n){
    if (k==1) return 1;
    for (int i=2; i<=sqrt(k); i++){
        if (NT[i] && k%i==0){
            return i;
        }
    }
    return k;
}
int main()
{
    freopen("Nhap.inp", "r", stdin);
    freopen("Nhap.out", "w", stdout);
    cin>> n;
    sangSo(n);
    for (int i=1; i<n+1; i++){
        cout<< UNTNN(i, n)<< endl;
    }
}

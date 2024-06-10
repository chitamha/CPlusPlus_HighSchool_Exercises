#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, x, A[1000001];
vector<int> check(1000001, 0);
vector<long long> F(1000001, 0);
int f(int x, int A[], int n){
    if ((F[x]!=0 && check[x]!=1) || (F[x]!=1 && check[x]==1)) return F[x];
    for (int i=0; i<n; i++){
        if (x>=A[i]){
            (F[x]+=f(x-A[i], A, n))%=MOD;
        }
    }
    return F[x];
}
int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> A[i];
        check[A[i]]=1;
        F[A[i]]=1;
    }
    F[0]=0;
    cout<< f(x, A, n);
}

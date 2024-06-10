#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define MOD (long long) 111539786
using namespace std;

struct Matrix{
    ll M[2][2];
    Matrix(){
        memset(M, 0, sizeof M);
    }
    friend Matrix operator * (Matrix A, Matrix B){
        Matrix C;
        for (ll i=0; i<2; i++){
            for (ll j=0; j<2; j++){
                for (ll k=0; k<2; k++){
                    (C.M[i][j]+=(A.M[i][k]%MOD)*(B.M[k][j]%MOD)%MOD)%=MOD;
                }
            }
        }
        return C;
    }
};

Matrix Pow(Matrix &A, ll k){
    if (k==0){
        Matrix DonVi;
        DonVi.M[0][0]=DonVi.M[1][1]=1;
        return DonVi;
    }
    Matrix tmp=Pow(A, k/2);
    tmp=tmp*tmp;
    if (k&1) tmp=tmp*A;
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        ll n; cin>> n;
        if (n==1 || n==0){
            cout<< n<< endl;
            continue;
        }
        Matrix A, B, C;
        A.M[0][0]=A.M[0][1]=A.M[1][0]=1;
        B.M[0][0]=B.M[1][0]=1;
        C=Pow(A, n-2)*B;
        cout<< (C.M[0][0]%MOD+C.M[1][0]%MOD)%MOD<< endl;
    }
    return 0;
}

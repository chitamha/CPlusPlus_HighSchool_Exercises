#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, MOD;

struct Matrix{
    ll M[3][3];
    Matrix(){
        memset(M, 0, sizeof M);
    }
    friend Matrix operator * (Matrix A, Matrix B){
        Matrix C;
        for (ll i=0; i<3; i++){
            for (ll j=0; j<3; j++){
                for (ll k=0; k<3; k++){
                    (C.M[i][j]+=(A.M[i][k]%MOD)*(B.M[k][j]%MOD)%MOD)%=MOD;
                }
            }
        }
        return C;
    }
};

Matrix Pow(Matrix A, ll k){
    if (k==0){
        Matrix DonVi;
        DonVi.M[0][0]=DonVi.M[1][1]=DonVi.M[2][2]=1;
        return DonVi;
    }
    Matrix tmp=Pow(A, k/2);
    tmp=tmp*tmp;
    if (k%2==1) tmp=tmp*A;
    return tmp;
}

int main(){
    freopen("LOCO.INP", "r", stdin);
    freopen("LOCO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> MOD;
    if (n==0) return cout<< 0, 0;
    else if (n==1 || n==2) return cout<< n, 0;
    Matrix A, B, C;
    A.M[0][0]=A.M[0][1]=A.M[0][2]=A.M[1][0]=A.M[2][1]=1;
    B.M[0][0]=2; B.M[1][0]=1; B.M[2][0]=1;
    C=Pow(A, n-2)*B;
    //Chú ý thứ tự nhân ma trận (dễ sai)
    cout<< C.M[0][0];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m, k, prime[105];
int A[105][105], F[105][105];

bool isprime(int x){
    for (int i=2; i<=sqrt(x); i++)
        if (x%i==0) return 0;
    return x>=2;
}

void ngto(){
    int cnt=1;
    prime[1]=2;
    for (int i=3; i<=100; i++){
        if (isprime(i)){
            cnt++;
            prime[cnt]=i;
        }
    }
    //for (int i=1; i<=25; i++) cout<< prime[i]<< " ";
    //cout<< endl;
}

int main(){
    cin>> n>> m>> k;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> A[i][j];
    ngto();
    //Khong can
    //for (int i=0; i<=k && prime[1]*i<=100; i++) F[1][prime[1]*i]=1;
    for (int i=0; i<=25; i++) F[i][0]=1;
    for (int i=1; i<=25; i++){
        for (int j=1; j<=100; j++){
            for (int h=0; h<=k; h++){
                if (j-h*prime[i]<0) break;
                F[i][j]+=F[i-1][j-h*prime[i]];
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cout<< F[25][A[i][j]]<< " ";
        cout<< endl;
    }
    return 0;
}

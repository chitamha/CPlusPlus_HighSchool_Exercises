#include <iostream>
#include <math.h>
using namespace std;
/*int n=10000000;
int prime[10000001];
void nt(){
    for (int i=0; i<=n; i++){
        prime[i]=1;
    }
    prime[0]=prime[1]=0;
    for (int i=2; i<=sqrt(n); i++){
        if (prime[i]){
            for (int j=i*i; j<=n; j+=i){
                prime[j]=0;
            }
        }
    }
}
int main(){
    nt();
    for (int i=0; i<=20; i++){
        if (prime[i]==1){
            cout<< i<< " ";
        }
    }
}*/
int main(){
    int n, m;
    cin>> n>> m;
    int A[n][m]; int B[m][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
        cin>> A[i][j];
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            B[i][j]=A[j][i];
            cout<< B[i][j]<< " ";
        }
        cout<< endl;
    }/*
     for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<< B[i][j]<< " ";
        }
        cout<< endl;
    }*/
}

#include <bits/stdc++.h>
using namespace std;
int dequytong(int n){
    if (n==0){
        return 0;
    }
    else
    {
        return n+dequytong(n-1);
    }
}
int dequytich(int n){
    if (n==0){
        return 1;
    }
    else
    {
        return n*dequytich(n-1);
    }
}
int dequysoFibonacci(int n){
    if (n==0 || n==1){
        return n;
    }
    else
    {
        return dequysoFibonacci(n-1)+dequysoFibonacci(n-2);
    }

}
int dequytohop(int n, int k){
    if (k==n || k==0){
        return 1;
    }
    else
    {
        return dequytohop(n-1, k-1)+dequytohop(n-1, k);
    }
}
int giaithua(int n){
    int tich=1;
    for (int i=1; i<=n; i++){
        tich*=i;
    }
    return tich;
}
int F[1000];
void fibo(int n){
    F[0]=0; F[1]=1;
    for (int i=2; i<=n; i++){
        F[i]=F[i-1]+F[i-2];
    }
}
int dequytcs(int n){
    if (n<10){
        return n;
    }
    else
    {   int ssum=0;
        ssum=n%10;
        return ssum+dequytcs(n/10);
    }

}
void dqsnp(int n){
    if (n<2){
        cout<< n%2;
    }
    else
    {
        dqsnp(n/2);
        cout<< n%2;
    }
}
int main(){/*
    fibo(1000);
    for (int i=0; i<=10; i++){
        cout<< F[i]<< " ";
    }
    cout<< endl;
    int n, k;
    cin>> n>> k;
    int m=n;
    cout<< dequytong(n)<< endl;
    cout<< dequytich(n);
    int sum=0, tich=1;
    for (int i=0; i<=n; i++){
        sum+=i;
        if (i!=0) tich*=i;
    }
    cout<< endl<< "Tong = "<< sum;
    cout<< endl<< "Tich = "<< tich;
    cout<< endl<< F[n-1];
    cout<< endl<< "So fibo thu "<< n<< " la "<< dequysoFibonacci(n-1);
    cout<< endl<< giaithua(n)/(giaithua(k)*giaithua(n-k));
    cout<< endl<< n<< "C"<< k<< " = "<< dequytohop(n, k);
    int ttong=0;
    while (n>0){
        ttong+=n%10;
        n=n/10;
    }
    cout<< endl<< ttong;
    cout<< endl<< dequytcs(m);*/
    int n;
    cin>> n;
    dqsnp(n);
}

#include <bits/stdc++.h>
using namespace std;
int fibo[92];
void nhapFibo(){
    fibo[0]=0; fibo[1]=1;
    for (int i=2; i<=92; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
}
int cnt, k=-1;
void cntFibo(int A[], int i, int n, int &cnt){
    if (!binary_search(fibo, fibo+n, A[i])){
        cnt=0;
    }
    else{
        ++cnt;
        cntFibo(A, i+1, n, cnt);

    }
}
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int mmax=0;
    for (int i=0; i<n; i++){
        cnt=0;
        cntFibo(A, i, n, cnt);
        cout<< cnt<< " ";
        mmax=max(mmax, cnt);
    }
    cout<< endl<< mmax;



}

#include <iostream>
#include <algorithm>
using namespace std;
int fibo[100];
void nhapFibo(){
    fibo[0]=0, fibo[1]=1;
    for (int i=2; i<=92; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
}
int cnt, chiSo=-1;
void demsoFibo(int A[],int i, int n){
    cnt=0;
    while((binary_search(fibo, fibo+n, A[i]))){
        ++cnt;
        if (!binary_search(fibo, fibo+n, A[i-1])){
            chiSo=i;
        }
        ++i;
    }
}
int main(){
    nhapFibo();
    for (int i=0; i<20; i++) cout<< fibo[i]<< " ";
    cout<< endl;
    int n;
    cin>> n;
    int A[n+1];
    A[0]=-1;
    for (int i=1; i<n+1; i++){
        cin>> A[i];
    }
    int mmax=0, k=-1;
    for (int i=1; i<n+1; i++){
        demsoFibo(A, i, n);
        if (mmax<=cnt){
            mmax=cnt;
            k=chiSo;
        }
    }
    cout<< k-1<< endl;
    if (k==-1){
        cout<< "Khong co so fibo";
        return 0;
    }
    cout<< mmax<< endl;
    for (int i=k; i<mmax+k; i++){
        cout<< A[i]<< " ";
    }
    return 0;
}

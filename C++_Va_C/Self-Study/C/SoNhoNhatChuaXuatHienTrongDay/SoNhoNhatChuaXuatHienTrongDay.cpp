/*#include <bits/stdc++.h>
using namespace std;

long long n, A[1000000], B[1000000], dem=0;
void xuatMang(int n, long long A[]){
    for (int i=0; i<n; i++){
        cout<< A[i]<< " ";
    }
}

int main(){
    cin>> n;
    long long max=0;
    for (int i=0; i<n; i++){
        cin>> A[i];
        if (max<=A[i]){
            max=A[i];}
        if (A[i]>0){
            B[dem]=A[i];
            dem++;
        }
    }
    xuatMang(n, A);
    for (int i=0; i<=n-2; i++){
        for (int j=i+1; j<=n-1; j++){
            if (A[i]>A[j]){
                long long tam=A[i];
                A[i]= A[j]; A[j]=tam;
            }
        }
    }
    long long j=1;
    if (dem!=0) {
        for (int i=0; i<dem+1; i++){
            if (j!=B[i]){
                cout<< j;
                break;
            }
            j++;
        }
    } else {cout<< "1";}
}*/
#include <iostream>
using namespace std;
int main(){



}

#include <bits/stdc++.h>
using namespace std;

char c;
int n, k, cnt=1;
int A[1000];

void Ql(int i){
    for (int j=1; j<=n; j++){
        A[i]=j;
        if (i==k){
            cout<< cnt++<< ": ";
            for (int h=1; h<=k; h++)
                cout<< char(A[h]+64);
            cout<< endl;
        } else Ql(i+1);
    }
}
//1 -> A(65)
//2 -> B(66)
//A[h] -> ...(64+A[h])
int main(){
    cin>> c>> k;
    n=c-'A'+1;
    Ql(1);
    return 0;
}

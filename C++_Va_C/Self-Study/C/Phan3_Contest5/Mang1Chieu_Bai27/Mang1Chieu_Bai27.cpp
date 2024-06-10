#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1000001]={0};
int main(){
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.INP", "w", stdout);
    int n;
    cin>> n;
    int A[n];
    int ln=-1e9;
    for (int i=0; i<n; i++){
        cin>> A[i];
        cnt[A[i]]+=1;
        if (ln<A[i]){
            ln=A[i];
        }
    }
    for (int i=0; i<=ln; i++){
        if (cnt[i]!=0)
            cout<< i<< " "<< cnt[i]<< endl;
    }
}

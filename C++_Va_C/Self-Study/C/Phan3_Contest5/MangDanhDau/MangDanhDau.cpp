#include <iostream>
using namespace std;
int cnt[1000001];
int main(){
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.INP", "w", stdout);
    int n;
    cin>> n;
    int A[n];
    int dem=0;
    for (int i=0; i<n; i++){
        cin>> A[i];
        cnt[A[i]]=1;
    }
    for (int i; i<1000001; i++){
        if(cnt[i]==1){
            ++dem;
        }
    }
    cout<< dem;
}

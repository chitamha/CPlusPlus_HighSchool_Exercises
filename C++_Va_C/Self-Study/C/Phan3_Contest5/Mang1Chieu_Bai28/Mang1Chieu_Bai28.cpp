#include <iostream>
using namespace std;
bool KT(int i, int A[]){
    for (int j=0; j<i; j++){
        if (A[j]==A[i]){
            return false;
        }
    }
    return true;
}
int cnt[1000001]={0};
int main(){
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
        cnt[A[i]]+=1;
    }
    for (int i=0; i<n; i++){
        if (KT(i, A)){
            cout<< A[i]<< " "<< cnt[A[i]]<< endl;
        }
    }
}

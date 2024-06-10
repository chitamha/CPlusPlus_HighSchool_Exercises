#include <bits/stdc++.h>
using namespace std;

int usntln(int n){
    int kq;
    for (int i=2; i<=sqrt(n); i++){
        while (n%i==0){
            kq=i;
            n/=i;
        }
    }
    if (n!=1) kq=n;
    return kq;
}

int main(){
    int t; cin>> t;
    while (t--){
        int n; cin>> n;
        cout<< usntln(n)<< endl;
    }
}

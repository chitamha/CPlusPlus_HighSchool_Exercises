#include <bits/stdc++.h>
using namespace std;

int checkSoDep(int n){
    if (n<=1) return 0;
    for (int i=2; i<=sqrt(n); i++){
        int dem=0;
        while (n%i==0){
            dem++;
            n/=i;
        }
        if (dem==1) return 0;
    }
    if (n!=1) return 0;
    return 1;
}

int main(){
    int t; cin>> t;
    while (t--){
        int a, b;
        cin>> a>> b;
        for (int i=a; i<=b; i++){
            if (checkSoDep(i))
                cout<< i<< " ";
        }
        cout<< endl;
    }
}

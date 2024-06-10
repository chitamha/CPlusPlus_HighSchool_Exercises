#include <bits/stdc++.h>
using namespace std;

bool checkNT(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return n>1;
}

int tongchuso(int n){
    if (n<10) return n;
    int tong=0;
    while (n){
        tong+=n%10;
        n=n/10;
    }
    return tong;
}

int tongusnt(int n){
    int tong=0;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            while (n%i==0){
                tong+=tongchuso(i);
                n/=i;
            }
        }
    }
    if (n!=1) tong+=tongchuso(n);
    return tong;
}
int main(){
    int t;
    cin>> t;
    while(t--){
        int n; cin>> n;
        cout<< checkNT(n)<< "\n"<< tongchuso(n)<< "\n"<< tongusnt(n)<< endl;
        if (!checkNT(n) && tongchuso(n)==tongusnt(n)){
            cout<< "YES"<< endl;
        } else cout<< "NO"<< endl;
    }
}

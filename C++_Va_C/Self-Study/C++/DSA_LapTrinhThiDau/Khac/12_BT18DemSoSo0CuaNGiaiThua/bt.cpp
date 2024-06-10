#include <bits/stdc++.h>
using namespace std;

int soso(int n){
    int cnt1=0, cnt2=0;
    for (int i=2; i<=n; i+=2){
        int tam=i;
        while (tam%2==0){
            cnt1++;
            tam/=2;
        }
    }
    for (int i=5; i<=n; i+=5){
        int tam=i;
        while (tam%5==0){
            cnt2++;
            tam/=5;
        }
    }
    return min(cnt1, cnt2);
}

int main(){
    int t;
    cin>> t;
    while (t--){
        int n;
        cin>> n;
        cout<< soso(n)<< endl;
    }
}

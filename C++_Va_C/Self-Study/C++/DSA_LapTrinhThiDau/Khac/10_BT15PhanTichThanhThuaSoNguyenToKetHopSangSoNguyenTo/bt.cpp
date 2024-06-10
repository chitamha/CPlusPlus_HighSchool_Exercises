#include <bits/stdc++.h>
using namespace std;

int uoc[1000001];
void uocnt(){
    for (int i=0; i<=1000000; i++){
        uoc[i]=i;
    }
    for (int i=2; i<=sqrt(1000000); i++){
        for (int j=i*i; j<=1000000; j+=i){
            if (uoc[j]==j){
                uoc[j]=i;
            }
        }
    }
}

void pt(int n){
    while (n!=1){
        int dem=0;
        int temp=uoc[n];
        while (n%temp==0){
            dem++;
            n/=temp;
        }
        cout<< temp<< "("<< dem<< ")"<< " ";
    }
    cout<< endl;
}


int main(){
    int t;
    cin>> t;
    uocnt();
    for (int i=1; i<=t; i++){
        int n;
        cin>> n;
        cout<< "#TC"<< i<< ": ";
        pt(n);
    }
    return 0;
}

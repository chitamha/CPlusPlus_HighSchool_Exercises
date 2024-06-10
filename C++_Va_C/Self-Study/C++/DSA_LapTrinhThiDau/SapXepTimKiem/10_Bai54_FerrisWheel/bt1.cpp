#include <bits/stdc++.h>
using namespace std;

int n, x, ans=0;

int main(){
    cin>> n>> x;
    int W[n];
    for (int i=0; i<n; i++) cin>> W[i];
    sort(W, W+n);
    int l=0, r=n-1;
    while (l<=r){
        if (l!=r){
            if (W[l]+W[r]<=x){
                ans++;
                l++; r--;
            } else{
                ans++;
                r--;
            }
        } else{
            if (W[l]<=x) ans++;
            l++; r--;
        }
    }
    cout<< ans;
    return 0;
}

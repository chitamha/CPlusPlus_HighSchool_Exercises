#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, X, ans;

int main(){
    cin>> t;
    while (t--){
        ans=1e9;
        cin>> n>> X;
        ll A[n+1];
        for (ll i=1; i<=n; i++) cin>> A[i];
        ll left=1, right=1;
        ll sum=0;
        /*
        while (right<=n){
            sum+=A[right];
            while (sum-A[left]>X && left<=n){
                sum-=A[left];
                left++;
            }
            if (sum>X) ans=min(ans, right-left+1);
            right++;

        }
        */
        while (right<=n){
            sum+=A[right];
            while (sum>X && left<=n){
                ans=min(ans, right-left+1);
                sum-=A[left];
                left++;
            }
            right++;

        }
        if (ans!=1e9)
            cout<< ans<< endl;
        else cout<< -1<< endl;
    }
    return 0;
}

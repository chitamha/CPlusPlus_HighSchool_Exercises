#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, cnt=0;

int main(){
    cin>> n>> k;
    ll A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    ll left=0, right=0;
    ll sum=0;
    while (right<n){
        sum+=A[right];
        while (sum>=k && left<n){
            if (sum==k) cnt++;
            sum-=A[left];
            left++;
        }
        right++;
    }
    cout<< cnt;
    return 0;
}

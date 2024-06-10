#include <bits/stdc++.h>
#define maxn 400005
#define ll long long
using namespace std;

int n, k;
vector<int> A;
ll dp[maxn];
/*
Gọi dp[i] là số lít rượu nhỏ nhất mà Bờm đã bỏ qua khi
xét đến vị trí i và sẽ tiếp tục bỏ qua chai thứ i
*/

int main(){
    cin>> n>> k; A.resize(n+10);
    ll sum=0;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        sum+=A[i];
        dp[i]=1e18;
    }
    dp[0]=0; dp[n+1]=1e18;
    for (int i=1; i<=n+1; i++){
        for (int j=max(0, i-k); j<=i-1; j++){
            dp[i]=min(dp[i], dp[j]+A[i]);
        }
        cout<< dp[i]<< " ";
    }
    cout<< endl;
    cout<< sum-dp[n+1];
    return 0;
}

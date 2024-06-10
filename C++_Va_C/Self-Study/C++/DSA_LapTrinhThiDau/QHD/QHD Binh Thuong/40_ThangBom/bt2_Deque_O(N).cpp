#include <bits/stdc++.h>
#define maxn 1000006
#define ll long long
using namespace std;

int n, k;
vector<int> A;
ll dp[maxn], before[maxn];
/*
Gọi dp[i] là số lít rượu nhỏ nhất mà Bờm đã bỏ qua khi
xét đến vị trí i và sẽ tiếp tục bỏ qua chai thứ i
*/

int main(){
    cin>> n>> k; A.resize(n+10);
    k++;
    ll sum=0;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        sum+=A[i];
    }
    deque<int> dq;
    dp[0]=0;
    dq.push_back(0);
    for (int i=1; i<=n+1; i++){
        while (!dq.empty() && dq.front()+k<i) dq.pop_front();
        dp[i]=dp[dq.front()]+A[i];
        before[i]=dq.front();
        while (!dq.empty() && dp[dq.back()]>=dp[i]) dq.pop_back();
        dq.push_back(i);
        //cout<< dp[i]<< " ";
    }
    //cout<< endl;
    cout<< sum-dp[n+1]<< endl;
    //Truy vết
    int tmp=n+1, cnt=0;
    vector<int> loai(n+10, 0);
    while (tmp!=0){
        loai[tmp]=1;
        cnt++;
        tmp=before[tmp];
    }
    cout<< n-cnt+1<< " "<< sum-dp[n+1]<< endl;
    for (int i=1; i<=n; i++){
        if (loai[i]==0) cout<< i<< " ";
    }
    return 0;
}

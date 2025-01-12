#include <bits/stdc++.h>
#define maxn 100005
#define fi first
#define se second
using namespace std;

int n, ans=0;
vector<int> A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    A.resize(n+5);
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=n, k;
    while (l<=r){
        k=(l+r)/2;
        deque<int> dq;
        int check=0;
        for (int i=1; i<=n; i++){
            while (!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (dq.front()<=i-k) dq.pop_front();
            if (i>=k && A[dq.front()]>=k){
                ans=max(ans, k);
                l=k+1;
                check=1;
                break;
            }
        }
        if (check==0) r=k-1;
        dq.clear();
        //cout<< k<< " "<< ans<< endl;
    }
    cout<< ans;
    return 0;
}

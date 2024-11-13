#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, m;
vector<int> A, B;

bool check(int d){
    int ma=-2e9, cnt=0;
    for (int i=1; i<=m; i++){
        auto it1=lower_bound(A.begin()+1, A.begin()+n+1, max(B[i]-d, ma));
        auto it2=upper_bound(A.begin()+1, A.begin()+n+1, B[i]+d)-1;
        ma=max(ma, B[i]+d+1);
        cnt+=it2-it1+1;
    }
    return cnt==n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    A.resize(n+2); B.resize(m+2);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++) cin>> B[i];
    int l=0, r=2e9, mid;
    while (l<=r){
        mid=(l+r)/2;
        //cout<< l<< " "<< r<< " "<< check(mid)<< " "<< mid<< endl;
        if (check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<< r+1;
    return 0;
}

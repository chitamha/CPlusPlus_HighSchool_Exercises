#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, A[100005], L[100005], R[100005], ans=0;
int MaxL[100005], MaxR[100005];

void process(){
    vector<int> v;
    for (int i=1; i<=n; i++){
        auto it=lower_bound(v.begin(), v.end(), A[i]);
        if (it==v.end()) v.push_back(A[i]);
        else *it=A[i];
        L[i]=v.size();
        MaxL[i]=v.back();
    }
    v.clear();
    for (int i=n; i>=1; i--){
        auto it=lower_bound(v.begin(), v.end(), A[i]);
        if (it==v.end()) v.push_back(A[i]);
        else *it=A[i];
        R[i]=v.size();
        MaxR[i]=v.back();
    }
    v.clear();
}

int main(){
    //freopen("SPSEQ.INP", "r", stdin);
    //freopen("SPSEQ.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    process();
    //for (int i=1; i<=n; i++) cout<< L[i]<< " "; cout<< endl;
    //for (int i=1; i<=n; i++) cout<< R[i]<< " "; cout<< endl;
    for (int i=1; i<=n; i++){
        if (A[i]>MaxL[i-1] && A[i]>MaxR[i+1])
            ans=max(ans, 2*min(R[i+1], L[i-1])+1);
    }
    cout<< ans;
    return 0;
}

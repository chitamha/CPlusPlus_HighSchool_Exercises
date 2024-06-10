#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n, A[maxn], F1[maxn], F2[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    vector<int> v1, v2;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        //cout<< i<< " "<< n+1-i<< endl;
        auto it=lower_bound(v1.begin(), v1.end(), A[i]);
        if (it==v1.end()) v1.push_back(A[i]);
        else *it=A[i];
        F1[i]=v1.size();
        auto it2=lower_bound(v2.begin(), v2.end(), A[n+1-i]);
        if (it2==v2.end()) v2.push_back(A[n+1-i]);
        else *it2=A[n+1-i];
        F2[n+1-i]=v2.size();
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (F1[i]==F2[i]) ans=max(ans, F1[i]*2-1);
    cout<< ans;
    return 0;
}

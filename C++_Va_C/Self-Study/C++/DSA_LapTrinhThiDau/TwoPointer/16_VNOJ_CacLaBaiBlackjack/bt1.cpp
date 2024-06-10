#include <bits/stdc++.h>
#define ll long long
#define maxn 5006
using namespace std;

ll n, A[maxn], ans=0;

void xuli(int id){
    ll sum1=0, sum2=0;
    vector<ll> Left, Right;
    for (int i=id; i>=1; i--){
        sum1+=A[i];
        Left.push_back(sum1);
    }
    for (int i=id+1; i<=n; i++){
        sum2+=A[i];
        Right.push_back(sum2);
    }
    if (id<=n/2){
        int siz=Left.size();
        for (int i=0; i<siz; i++){
            auto it=lower_bound(Right.begin(), Right.end(), Left[i]);
            if (it!=Right.end() && *it==Left[i]) ans=max(ans, 1ll*(it-Right.begin()+1+i+1));
        }
    } else{
        int siz=Right.size();
        for (int i=0; i<siz; i++){
            auto it=lower_bound(Left.begin(), Left.end(), Right[i]);
            if (it!=Left.end() && *it==Right[i]) ans=max(ans, 1ll*(it-Left.begin()+1+i+1));
        }
    }
    Left.clear(); Right.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++) xuli(i);
    cout<< ans;
    return 0;
}
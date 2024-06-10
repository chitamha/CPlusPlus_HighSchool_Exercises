#include <bits/stdc++.h>
#define maxn 5005
#define fi first
#define se second
#define ll long long
using namespace std;

int n; ll ans=0;
vector<pair<int, int>> A;

int tknp1(int x, int left){
    int l=left, r=A.size()-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid].fi>x) r=mid-1;
        else l=mid+1;
    }
    return r+1;
}

int tknp2(int x, int left){
    int l=left, r=A.size()-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid].fi<x) l=mid+1;
        else r=mid-1;
    }
    return l-1;
}

int main(){
    freopen("TRIANGLES.INP", "r", stdin);
    freopen("TRIANGLES.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    map<int, int> Count;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        Count[x]++;
    }
    for (auto it:Count) A.push_back({it.fi, it.se});
    for (auto it:A){
        if (it.se>=3) ans++;
        if (it.se>=2) ans+=tknp2(2*(it.fi), 0);
    }
    n=A.size();
    /*
    for (int j=1; j<n-1; j++){
        int i=0, k=j+1;
        while (i<j && k<n){
            if (A[j].fi<=A[k].fi-A[i].fi) i++;
            else ans++, k++; {}
        }
    }
    */
    for (int i=0; i<n-2; i++){
        for (int j=i+1; j<n-1; j++){
            ans+=max(tknp2(A[i].fi+A[j].fi, j+1)-tknp1(A[j].fi-A[i].fi, j+1)+1, 0);
        }
    }
    cout<< ans;
    return 0;
}

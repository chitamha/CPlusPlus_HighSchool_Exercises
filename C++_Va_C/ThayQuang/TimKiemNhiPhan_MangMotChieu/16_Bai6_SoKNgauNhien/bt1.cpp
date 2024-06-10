#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> A(100005, 0);
map<int, int> mp;

bool check(int k){
    mp.clear();
    for (int i=1; i<=n; i++) mp.insert({A[i], 0});
    for (int i=1; i<=k; i++) mp[A[i]]++;
    for (int i=k+1; i<=n; i++){
        if (mp[A[i]]>0) mp[A[i]]++;
        if (mp[A[i-k]]>0) mp[A[i-k]]--;
    }
    for (int i=1; i<=k; i++) if (mp[A[i]]>0) return 1;
    return 0;
}

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=n; ans=n;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}

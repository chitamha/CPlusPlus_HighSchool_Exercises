#include <bits/stdc++.h>
using namespace std;

int n, s, ans=0;
vector<int> v;

int Dem(int k, int en, int x){
    int l=k, r=en-1, id=-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (v[mid]==x){
            id=mid;
            l=mid+1;
        } else if (v[mid]>x) r=mid-1;
        else if (v[mid]<x) l=mid+1;
    }
    return max(id-k+1, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> s; v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i];
    sort(v.begin()+1, v.begin()+1+n);
    for (int i=1; i<=n; i++){
        int id=lower_bound(v.begin()+1, v.begin()+1+i, s-v[i])-v.begin();
        if (v[id]==s-v[i]) ans+=Dem(id, i, s-v[i]);
    }
    cout<< ans;
    return 0;
}

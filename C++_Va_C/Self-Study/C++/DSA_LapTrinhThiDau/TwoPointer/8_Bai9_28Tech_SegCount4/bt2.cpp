#include <bits/stdc++.h>
using namespace std;

int n, K, d, ans=0;
multiset<int> ms;

int main(){
    cin>> n>> K;
    int A[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1;
    ms.insert(A[l]);
    for (l; l<=n; l++){
        while (ms.size()>=1 && (*(ms.rbegin())-*(ms.begin())<=K)){
            ms.insert(A[r]);
            r++;
        }
        if (r>l+1) ans+=r-l-1;
        else ans+=1;
        auto it=ms.find(A[l]);
        ms.erase(it);
    }
    cout<< ans;
    return 0;
}

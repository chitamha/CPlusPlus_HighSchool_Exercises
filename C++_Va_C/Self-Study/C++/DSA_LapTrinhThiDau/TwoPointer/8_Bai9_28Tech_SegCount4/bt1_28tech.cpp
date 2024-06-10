#include <bits/stdc++.h>
using namespace std;

int n, K, d, ans=0;
multiset<int> ms;

int main(){
    cin>> n>> K;
    int A[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1;
    for (r; r<=n; r++){
        ms.insert(A[r]);
        while (ms.size()!=0 && (*(ms.rbegin())-*(ms.begin())>K)){
            auto it=ms.find(A[l]);
            ms.erase(it);
            l++;
        }
        ans+=r-l+1;
    }
    cout<< ans;
    return 0;
}

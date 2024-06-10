#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> A;

int main(){
    cin>> t;
    while (t--){
        int n, k, ans=0;
        cin>> n>> k;
        A.resize(n+1);
        for (int i=1; i<=n; i++) cin>> A[i];
        sort(A.begin(), A.end());
        for (int i=1; i<=n; i++){
            auto it=upper_bound(A.begin()+i+1, A.end(), k-A[i]);
            ans+=A.end()-it;
        }
        cout<< ans<< endl;
        A.clear();
    }
    return 0;
}

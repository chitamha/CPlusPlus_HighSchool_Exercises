#include <bits/stdc++.h>
using namespace std;

int n, K, ans=0;
vector<int> A(100005);

int main(){
    cin>> n>> K;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    int l=1, r=1;
    map<int, int> mp;
    for (r; r<=n; r++){
        mp[A[r]]++;
        while (mp.size()>K && l<=n){
            mp[A[l]]--;
            if (mp[A[l]]==0){
                mp.erase(A[l]);
            }
            l++;
        }
        ans+=r-l+1;
    }
    cout<< ans;
    return 0;
}

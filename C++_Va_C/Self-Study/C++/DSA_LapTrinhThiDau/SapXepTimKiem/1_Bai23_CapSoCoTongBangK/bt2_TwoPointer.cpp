#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> A;

int main(){
    cin>> t;
    while (t--){
        int n, k;
        long long ans=0;
        cin>> n>> k;
        A.resize(n+1);
        for (int i=1; i<=n; i++) cin>> A[i];
        sort(A.begin(), A.end());
        int l=1, r=n;
        int cnt=0;
        while (l<r){
            if (A[l]+A[r]==k){
                cnt++;
                r--;
                cout<< cnt<< endl;
            } else if (A[l]+A[r]>k){
                r--;
            } else{
                l++;
                if (A[l]==A[l-1]){
                    if (A[l]+A[l-1]==k){
                        ans+=cnt;
                        cnt--;
                        ans+=cnt;
                        l++;
                    } else{
                        ans+=cnt+cnt;
                        l++;
                    }
                } else{
                    ans+=cnt;
                    cnt=0;
                }
            }
        }
        cout<< ans<< endl;
        A.clear();
    }
    return 0;
}

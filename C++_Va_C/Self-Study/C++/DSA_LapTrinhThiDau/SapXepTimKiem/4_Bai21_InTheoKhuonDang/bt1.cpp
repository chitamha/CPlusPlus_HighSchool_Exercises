#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> A;

int main(){
    cin>> t;
    while (t--){
        int n;
        cin>> n;
        A.resize(n+1);
        for (int i=1; i<=n; i++) cin>> A[i];
        sort(A.begin(), A.end());
        int l=1, r=n;
        while (l<=r){
            if (l!=r)
                cout<< A[r]<< " "<< A[l]<< " ";
            else cout<< A[r];
            r--;
            l++;
        }
        cout<< endl;
        A.clear();
    }
    return 0;
}

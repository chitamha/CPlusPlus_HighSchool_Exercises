#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>> n;
    long long A[n];
    for (int i=0; i<n; i++) cin>> A[i];

    vector<long long> F;
    for (int i=0; i<n; i++){
        auto it=lower_bound(F.begin(), F.end(), A[i]);
        if (it==F.end()) F.push_back(A[i]);
        else *it=A[i];
    }
    cout<< F.size();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long tc, n, k, t, A[100001];

bool solution(){
    cin>> n>> k>> t;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    multiset<int> s;
    s.insert(A[0]);
    for (int j=1; j<k; j++){
        auto it=s.lower_bound(A[j]-t);
        if (it!=s.end() && *it<=A[j]+t){
            return 1;
        }
        s.insert(A[j]);
    }
    for (int j=k; j<n; j++){
        s.erase(s.find(A[j-k]));
        auto it=s.lower_bound(A[j]-t);
        if (it!=s.end() && *it<=A[j]+t){
            return 1;
        }
        s.insert(A[j]);
    }
    return 0;
}

int main(){
    cin>> tc;
    while (tc--){
        if (solution()) cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long A[100001];

bool solve(int k, long long A[], set<long long> s){
    for (int i=0; i<k; i++){
        if (s.count(A[i])){
            return 1;
        } else
            s.insert(A[i]);
    }
    for (int i=k; i<n; i++){
        s.erase(A[i-k]);
        if (s.count(A[i])) return 1;
        s.insert(A[i]);
    }
    return 0;
}

int main(){
    cin>> t;
    while (t--){
        cin>> n>> k;
        for (int i=0; i<n; i++) cin>> A[i];
        set<long long> s;
        if (solve(k, A, s)) cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}

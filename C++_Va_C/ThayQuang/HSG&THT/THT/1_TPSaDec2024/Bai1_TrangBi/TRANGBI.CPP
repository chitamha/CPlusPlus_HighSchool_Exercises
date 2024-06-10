#include <bits/stdc++.h>
using namespace std;

long long n;
int m, cnt=0;
vector<int> A;

int main(){
    freopen("TRANGBI.INP", "r", stdin);
    freopen("TRANGBI.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int x; cin>> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    int siz=A.size();
    for (int i=0; i<siz; i++){
        if (n>=A[i]){
            cnt++;
            n-=A[i];
        } else break;
    }
    cout<< cnt;
    return 0;
}

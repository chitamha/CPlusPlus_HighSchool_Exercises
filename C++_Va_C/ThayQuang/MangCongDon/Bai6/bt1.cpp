#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, k, A[maxn], preS[maxn];
vector<pair<int, int>> B(maxn);

void out(int l, int r){
    if (preS[r+1]-preS[l]<k) cout<< "YES";
    else cout<< "NO";
}

int main(){
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin>> n>> k;
    preS[0]=0;
    for (int i=1; i<n+1; i++){
        cin>> A[i];
        preS[i]=preS[i-1]+A[i];
    }
    for (int i=1; i<k+1; i++){
        cin>> B[i].first>> B[i].second;
        out(B[i].first, B[i].second);
        cout<< endl;
    }
    return 0;
}

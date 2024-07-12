#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, A[30], ans=0;

void Try(int id, int w1, int w2){
    if (id>n){
        if (w1==w2) ans=max(ans, w1);
        return;
    }
    Try(id+1, w1, w2);
    Try(id+1, w1+A[id], w2);
    Try(id+1, w1, w2+A[id]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    Try(1, 0, 0);
    cout<< ans;
    return 0;
}

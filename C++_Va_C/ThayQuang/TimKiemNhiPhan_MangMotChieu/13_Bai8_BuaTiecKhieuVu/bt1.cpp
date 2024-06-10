#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n, cnt=0;
vector<int> BC, BT, GC, GT;

void solution(vector<int> A, vector<int> B){
    //A thap; B cao
    int siz1=A.size(), siz2=B.size();
    int l=0, r=siz2-1;
    while (l<=siz1-1 && r>=0){
        if (abs(A[l])>B[r]){
            cnt++;
            l++; r--;
        } else r--;
    }
}

int main(){
    //freopen("DANCING.INP", "r", stdin);
    //freopen("DANCING.OUT", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        if (x>0) BC.push_back(x);
        else BT.push_back(x);
    }
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        if (x>0) GC.push_back(x);
        else GT.push_back(x);
    }
    sort(BC.begin(), BC.end());
    sort(BT.begin(), BT.end());
    sort(GC.begin(), GC.end());
    sort(GT.begin(), GT.end());
    solution(GT, BC);
    solution(BT, GC);
    cout<< cnt;
    return 0;
}

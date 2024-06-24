#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, Vec[50];
vector<ll> A, B, C;

void Try(int siz, int en, vector<ll> &Chua, ll sum){
    if (siz>en){
        Chua.push_back(sum);
        return;
    }
    Try(siz+1, en, Chua, sum);
    Try(siz+1, en, Chua, sum+Vec[siz]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> Vec[i];
    Try(1, n/2, A, 0ll);
    Try(n/2+1, n, B, 0ll);
    for (int i=0; i<A.size(); i++){
        for (int j=0; j<B.size(); j++){
            C.push_back(A[i]+B[j]);
        }
    }
    int tmpcnt=0;
    for (int x:C){
        tmpcnt++;
        cout<< x<< " ";
    }
    cout<< endl<< tmpcnt<< endl;
    return 0;
}

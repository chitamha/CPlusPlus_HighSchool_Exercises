#include <bits/stdc++.h>
using namespace std;

int t;
int A[105];
int DanhDau[105];

int main(){
    cin>> t;
    while (t--){
        memset(A, 0, sizeof A);
        memset(DanhDau, 0, sizeof DanhDau);
        int n, m;
        cin>> n>> m;
        for (int i=1; i<=n; i++) cin>> A[i];
        for (int i=1; i<=m; i++){
            int x; cin>> x;
            DanhDau[x]=1;
        }
        int cnt=0;
        for (int i=1; i<=n; i++){
            if (DanhDau[i]==1) cnt++;
            else{
                if (cnt>0){
                    sort(A+i-cnt, A+i+1);
                }
                cnt=0;
            }
        }
        bool check=false;
        for (int i=2; i<=n; i++){
            if (A[i]<A[i-1]){
                check=true;
                break;
            }
        }
        if (!check) cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}

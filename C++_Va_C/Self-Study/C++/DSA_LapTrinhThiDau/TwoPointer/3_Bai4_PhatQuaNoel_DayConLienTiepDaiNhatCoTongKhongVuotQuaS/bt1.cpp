#include <bits/stdc++.h>
using namespace std;

int n, W, cnt=0, sum=0;
vector<int> A;
// day con lien tiep dai nhat co tong <= S

int main(){
    cin>> n>> W;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1, dem=0;
    for (l; l<=n; l++){
        for (r; r<=n; r++){
            if (sum+A[r]<=W){
                dem++;
                sum+=A[r];
            } else break;
        }
        if (sum<=W) cnt=max(cnt, dem);
        sum-=A[l];
        dem--;
    }
    cout<< cnt;
    return 0;
}

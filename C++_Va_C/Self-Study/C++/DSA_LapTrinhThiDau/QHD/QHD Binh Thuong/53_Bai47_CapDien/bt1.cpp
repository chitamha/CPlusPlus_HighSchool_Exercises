#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
double A[205][205], B[205][205];
pair<int, int> td[205];

double dis(int i, int j){
    double dx=td[i].fi-td[j].fi;
    double dy=td[i].se-td[j].se;
    return dx*dx+dy*dy;
}

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> td[i].fi>> td[i].se;
    memset(A, 62, sizeof A);
    memset(B, 62, sizeof B);
    for (int i=0; i<=n; i++)
        A[i][0]=A[0][i]=B[i][0]=B[0][i]=0;
    for (int i=0; i<=n; i++)
        A[i][0]=A[0][i]=B[i][0]=B[0][i]=0;
    for (int i=n; i>=1; i--){
        for (int j=1; j<=n; j++){
            A[i][j]=min({A[i][j], dis(i, i+1)+A[i+1][j], dis(i, j)+B[i+1][j]});
            B[i][j]=min({B[i][j], dis(j, j+1)+A[j+1][i], dis(i, j)+B[j+1][i]});
        }
    }
    cout<< A[1][n];
    return 0;
}

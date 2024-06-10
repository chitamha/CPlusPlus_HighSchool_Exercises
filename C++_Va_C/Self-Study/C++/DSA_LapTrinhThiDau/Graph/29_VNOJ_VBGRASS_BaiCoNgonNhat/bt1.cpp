#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n, m, cnt=0;
char A[maxn][maxn];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void loang(int i, int j){
    for (int k=0; k<4; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=1 && i1<=n && j1>=1 && j1<=m && A[i1][j1]=='#'){
            A[i1][j1]='.';
            loang(i1, j1);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cin>> A[i][j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (A[i][j]=='#'){
                cnt++;
                A[i][j]=='.';
                loang(i, j);
            }
        }
    }
    cout<< cnt;
    return 0;
}

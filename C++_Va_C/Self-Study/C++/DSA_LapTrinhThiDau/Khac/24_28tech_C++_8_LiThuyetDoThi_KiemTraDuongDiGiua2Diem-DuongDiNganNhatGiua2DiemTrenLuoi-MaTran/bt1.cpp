#include <bits/stdc++.h>
using namespace std;
// o: di duoc
// x: bi chan
int n, m;
char A[1005][1005];
int sB[1005][1005];
int xA, yA, xB, yB;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

bool DFS(int i, int j){
    if (A[i][j]=='B') return true;
    cout<< i<< " "<< j<< endl;
    A[i][j]='x';
    for (int k=0; k<4; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=1 && i1<=n && j1>=1 && j1<=m && A[i1][j1]!='x'){
            if (DFS(i1, j1)) return true;
        }
    }
    return false;
}

bool BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        auto f=q.front();
        q.pop();
        int i1=f.first, j1=f.second;
        cout<< i1<< " "<< j1<< endl;
        if (A[i1][j1]=='B') return true;
        A[i1][j1]='x';
        for (int k=0; k<4; k++){
            int i2=i1+dx[k];
            int j2=j1+dy[k];
            if (i2>=1 && i2<=n && j2>=1 && j2<=m && A[i2][j2]!='x'){
                sB[i2][j2]=sB[i1][j1]+1;
                q.push({i2, j2});
            }
        }
    }
    return false;
}
void init(){
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>> A[i][j];
            if (A[i][j]=='A'){
                xA=i; yA=j;
            } else if (A[i][j]=='B'){
                xB=i; yB=j;
            }
        }
    }
    if (BFS(xA, yA)) cout<< "Di duoc\n";
    else cout<< "Bi chan\n";
    cout<< sB[xB][yB]<< endl;
}

int main(){
    freopen("INPUT.inp", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    return 0;
}

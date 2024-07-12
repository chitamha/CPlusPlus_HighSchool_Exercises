#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int c, s, visited[5005][5005], ans=0;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

bool check(int i, int j){
    return i>=0 && j>=0 && visited[i][j]==0;
}

void BFS(int i, int j, int cnt){
    if (cnt>s) return;
    visited[i][j]=1;
    ans++;
    for (int k=0; k<4; k++){
        if (check(i+dx[k], j+dy[k]))
            BFS(i+dx[k], j+dy[k], cnt+1);
    }
}

int main(){
    freopen("ANT.INP", "r", stdin);
    freopen("ANT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> c>> s;
    for (int i=1; i<=c; i++){
        int x, y; cin>> x>> y;
        visited[x+1000][y+1000]=1;
    }
    BFS(1000, 1000, 0);
    cout<< ans;
    return 0;
}

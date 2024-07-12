#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

string s;
int n, A[4][2*maxn], d[4][2*maxn], visited[4][2*maxn];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

bool check(int i, int j){
    return (i>=1 && i<=3 && j>=1 && j<=2*n+1);
}

void bfs(){
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    d[1][1]=0;
    while (!dq.empty()){
        int x=dq.front().fi;
        int y=dq.front().se;
        dq.pop_front();
        visited[x][y]=1;
        for (int k=0; k<4; k++){
            int i=x+dx[k];
            int j=y+dy[k];
            if (check(i, j) && visited[i][j]==0){
                if (A[i][j]==0) dq.push_front({i, j});
                else dq.push_back({i, j});
                d[i][j]=min(d[i][j], d[x][y]+A[i][j]);
            }
        }
    }
}

int main(){
    freopen("VUOTSONG.INP", "r", stdin);
    freopen("VUOTSONG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(d, 62, sizeof d);
    cin>> s; n=s.size();
    s=' '+s;
    for (int i=1; i<=2*n+1; i++) A[2][i]=1;
    for (int i=1; i<=n; i++){
        if (s[i]=='L') A[1][2*i]=1;
        else if (s[i]=='R') A[3][2*i]=1;
        else A[1][2*i]=A[3][2*i]=1;
    }
    /*
    for (int i=1; i<=3; i++){
        for (int j=1; j<=2*n+1; j++) cout<< A[i][j]<< " ";
        cout<< endl;
    }
    */
    bfs();
    cout<< d[3][2*n+1];
    return 0;
}

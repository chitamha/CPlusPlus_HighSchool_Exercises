#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, A[55][55], d[55][55], visited[55][55];
pair<int, int> before[55][55];
int dx[]={1, 0, 0, -1, 0};
int dy[]={0, -1, 1, 0, 0};
struct ele{
    int x, y, dis;
};

bool ingrid(int i, int j){
    return i>=1 && j>=1 && i<=n && j<=m;
}

int get(int x, int tim){
    tim%=4;
    while (tim--){
        if (x==0) x=3;
        else x--;
    }
    return x;
}

int main(){
    cin>> n>> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> A[i][j], d[i][j]=1e9; {}
    queue<ele> q;
    d[n][1]=0;
    q.push({n, 1, 0});
    //cout<< "Duyet"<< endl;
    while (!q.empty()){
        int u=q.front().x;
        int v=q.front().y;
        int dis=q.front().dis;
        if (u==1 && v==m) break;
        q.pop();
        for (int k=0; k<5; k++){
            int i=u+dx[k], j=v+dy[k];
            if (!ingrid(i, j)) continue;
            if (visited[i][j]==0 && get(A[i][j], dis+1)!=0){
                if (d[i][j]>dis+1){
                    d[i][j]=dis+1;
                    before[i][j]={u, v};
                    q.push({i, j, d[i][j]});
                } else if (i==u && j==v) q.push({i, j, dis+1});
            }
        }
        visited[u][v]=1;
        //cout<< u<< " "<< v<< endl;
    }
    cout<< d[1][m]<< endl;
    /*
    int i=1, j=m;
    stack<pair<int, int>> st;
    st.push({1, m});
    while (d[i][j]!=0){
        st.push({before[i][j].fi, before[i][j].se});
        i=before[i][j].fi, j=before[i][j].se;
    }
    cout<< "Truy vet"<< endl;
    while (!st.empty()){
        cout<< st.top().fi<< " "<< st.top().se<< endl;
        st.pop();
    }
    */
    return 0;
}

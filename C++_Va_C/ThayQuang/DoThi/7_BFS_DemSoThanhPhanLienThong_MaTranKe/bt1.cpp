#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n, m, u, v, cnt=0;
int a[1001][1001];
int visited[1001];

void init(){
    cin>> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
          cin>> a[i][j];
        }
    }
}

int main(){
    init();
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            cnt++;
            q.push(i);
            visited[i]=1;
            while (!q.empty()){
                int u=q.front();
                q.pop();
                for (int v=1; v<=n; v++){
                    if (a[u][v]==1 && !visited[v]){
                        q.push(v);
                        visited[v]=1;
                    }
                }
            }
        }
    }
    cout<< cnt;
    return 0;
}

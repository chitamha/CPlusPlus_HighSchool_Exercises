#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1000006
using namespace std;

int n, d, ma=0, F[105][maxn];
pair<int, int> before[105][maxn];
struct music{
    int en, w, id;
} A[maxn];

bool cmp(music A, music B){
    return A.en<B.en;
}

int main(){
    cin>> n>> d;
    for (int i=1; i<=n; i++){
        cin>> A[i].en;
        A[i].id=i;
    }
    for (int i=1; i<=n; i++) cin>> A[i].w;
    sort(A+1, A+1+n, cmp);
    for (int i=1; i<=n; i++){
        for (int j=d; j<=A[i].en; j++){
            if (F[i][j]<F[i-1][j]){
                F[i][j]=F[i-1][j];
                before[i][j]={i-1, j};
            }
            if (F[i][j]<F[i-1][j-d]+A[i].w){
                F[i][j]=F[i-1][j-d]+A[i].w;
                before[i][j]={i-1, j-d};
            }
            if (F[i][j]<F[i][j-d]){
                F[i][j]=F[i][j-d];
                before[i][j]={i, j-d};
            }
        }
    }
    int id=0;
    for (int i=d; i<=A[n].en; i++) if (F[n][i]>F[n][id]) id=i;
    cout<< F[n][id]<< endl;
    int tmp=n;
    stack<int> st;
    while (F[tmp][id]>0){
        int u=before[tmp][id].fi, v=before[tmp][id].se;
        if (u==tmp-1 && v==id-d) st.push(A[tmp].id);
        tmp=u, id=v;
    }
    while (!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    return 0;
}

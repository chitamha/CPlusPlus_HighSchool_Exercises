#include <bits/stdc++.h>
#define fi first
#define se second
#define dis 10005
using namespace std;

int n, k, ma=0, mi=0, A[105], F[105][2*dis];
pair<int, int> before[105][2*dis];

int main(){
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        ma+=A[i];
        if (i==1) mi=A[i];
        else mi-=A[i];
    }
    F[0][0+dis]=F[1][A[1]+dis]=1;
    before[1][A[1]+dis]={0, 0+dis};
    for (int i=2; i<=n; i++){
        for (int j=mi; j<=ma; j++){
            int tmp=j+dis;
            if (F[i][tmp]==1) continue;
            if (F[i-1][tmp-A[i]]==1){
                F[i][tmp]=1;
                before[i][tmp]={i-1, tmp-A[i]};
            } else if (F[i-1][tmp+A[i]]==1){
                F[i][tmp]=1;
                before[i][tmp]={i-1, tmp+A[i]};
            }
        }
    }
    cout<< F[n][k+dis]<< endl;
    int i=n, j=k+dis;
    stack<char> st;
    while (j!=dis){
        if (j<before[i][j].se) st.push('-');
        else st.push('+');
        i--;
        j=before[i][j].se;
        //cout<< j<< endl;
    }
    while (!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int F, V, A[105][105], dp[105][105];

int main(){
    cin>> F>> V;
    for (int i=1; i<=F; i++) for (int j=1; j<=V; j++) cin>> A[i][j];
    for (int i=1; i<=F; i++){
        for (int j=1; j<=V; j++){
            dp[i][j]=max(dp[i][j-1], dp[i-1][j-1]+A[i][j]);
        }
    }
    cout<< dp[F][V]<< " ";
    int x=F, y=V;
    stack<int> st;
    while (dp[x][y]>0){
        if (dp[x][y]==dp[x][y-1]) y--;
        else{
            st.push(y);
            x--;
            y--;
        }
    }
    while (!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    return 0;
}

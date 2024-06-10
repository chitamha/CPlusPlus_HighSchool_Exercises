#include <bits/stdc++.h>
using namespace std;

int n, k, A[55][55], X[10], used[55], preS[2505], ans=1e9;
vector<int> CH;

void Try(int i, int sum){
    if (sum>=ans || ans<=sum+preS[k-i+1]) return;
    for (int j=2; j<=n; j++){
        if (used[j]==1) continue;
        X[i]=j;
        used[j]=1;
        sum+=A[X[i-1]][X[i]];
        if (i==k){
            sum+=A[X[k]][1];
            //cout<< sum<< "\n";
            if (ans>sum){
                ans=sum;
                CH.clear();
                for (int id=1; id<=k; id++) CH.push_back(X[id]);
            }
            sum-=A[X[k]][1];
        } else Try(i+1, sum);
        used[j]=0;
        sum-=A[X[i-1]][X[i]];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    int cnt=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
            if (A[i][j]!=0) preS[++cnt]=A[i][j];
        }
    }
    sort(preS+1, preS+1+cnt);
    /*
    for (int i=1; i<=cnt; i++) cout<< preS[i]<< " ";
    cout<< "\n";
    */
    for (int i=1; i<=cnt; i++) preS[i]+=preS[i-1];
    /*
    for (int i=1; i<=cnt; i++) cout<< preS[i]<< " ";
    cout<< "\n";
    */
    used[1]=1; X[1]=1;
    Try(2, 0);
    cout<< ans<< "\n";
    for (int x:CH) cout<< x<< " ";
    return 0;
}

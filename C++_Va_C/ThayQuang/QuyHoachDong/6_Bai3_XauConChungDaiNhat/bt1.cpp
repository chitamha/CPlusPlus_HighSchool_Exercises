#include <bits/stdc++.h>
#define maxn 105
using namespace std;

string s1, s2;
int n, m;
int F[maxn][maxn];

int main(){
    //freopen("LCS.INP", "r", stdin);
    //freopen("LCS.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s1>> s2;
    swap(s1, s2);
    int n=s1.size(), m=s2.size();
    s1=' '+s1; s2=' '+s2;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i]==s2[j])
                F[i][j]=F[i-1][j-1]+1;
            else F[i][j]=max(F[i-1][j], F[i][j-1]);
        }
    }
    //cout<< F[n][m]<< endl;
    string lcs;
    vector<int> v1, v2;
    while (F[n][m]!=0){
        if (s1[n]==s2[m]){
            v1.push_back(n); v2.push_back(m);
            lcs=s1[n]+lcs;
            n--; m--;
        } else{
            if (F[n][m]==F[n-1][m]) n--;
            else m--;
        }
    }
    cout<< lcs<< endl;
    for (int i=v1.size()-1; i>=0; i--) cout<< v1[i]<< " ";
    cout<< endl;
    for (int i=v2.size()-1; i>=0; i--) cout<< v2[i]<< " ";
    return 0;
}

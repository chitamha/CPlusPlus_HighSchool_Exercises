#include <bits/stdc++.h>
using namespace std;

int F[1005][1005];
int A[1005][1005];
int main(){
    string s, t;
    cin>> s;
    cin>> t;
    int n1=s.size();
    int n2=t.size();
    s="@"+s;
    t="@"+t;
    F[0][0]=0;
    for (int i=1; i<=n1; i++){
        for (int j=1; j<=n2; j++){
            F[i][j]=0;
            if (s[i]==t[j]){
                F[i][j]=F[i-1][j-1]+1;
            } else {
                F[i][j]=max(F[i][j-1], F[i-1][j]);
            }
        }
    }
    cout<< F[n1][n2];
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, t;
    cin>> s>> t;
    int n1=s.size();
    int n2=t.size();
    s="@"+s; t="@"+t;
    // F[i][j]: so ki tu chung cua 2 xau, tu 1->i va tu 1->j
    int F[n1+1][n2+1];
    F[0][0]=0;
    for (int i=1; i<=n1; i++) F[i][0]=0;
    for (int j=1; j<=n2; j++) F[0][j]=0;
    for (int i=1; i<=n1; i++){
        for (int j=1; j<=n2; j++){
            if (s[i]==t[j]){
                F[i][j]=max({F[i-1][j-1], F[i-1][j], F[i][j-1]})+1;
            } else{
                F[i][j]=max({F[i-1][j-1], F[i-1][j], F[i][j-1]});
            }
        }
    }
    cout<< F[n1][n2];
    return 0;
}
*/

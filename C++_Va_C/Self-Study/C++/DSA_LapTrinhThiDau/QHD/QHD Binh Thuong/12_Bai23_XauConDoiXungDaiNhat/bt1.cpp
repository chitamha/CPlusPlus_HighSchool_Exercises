#include <bits/stdc++.h>
#define maxn 2005
using namespace std;

int F[maxn][maxn];
// F[i][j]: true || false
// tra ve true neu xau con tu i->j doi xung
// tra ve false neu xau con tu i->j khong doi xung
// => i-j+1 do dai xau con doi xung
string s;
int n;

int main(){
    getline(cin, s);
    n=s.size();
    s="@"+s;
    int maxlen=1;
    for (int i=n; i>=1; i--){
        for (int j=i; j<=n; j++){
            if (i==j){
                F[i][j]=1;
                maxlen=max(maxlen, j-i+1);
            }
            else if (j-i+1==2 && s[i]==s[j]){
                F[i][j]=1;
                maxlen=max(maxlen, j-i+1);
            }
            else if (s[i]==s[j] && F[i+1][j-1]){
                F[i][j]=1;
                maxlen=max(maxlen, j-i+1);
            }
            else F[i][j]=0;
        }
    }
    cout<< maxlen;
    return 0;
}

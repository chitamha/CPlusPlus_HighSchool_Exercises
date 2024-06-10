#include <bits/stdc++.h>
using namespace std;

int t, n;
char v[25][25];

char process(int i, int j){
    for (char c='A'; c<='Z'; c++){
        if (v[i][j-1]!=c && v[i-1][j]!=c && v[i+1][j]!=c && v[i][j+1]!=c)
            return c;
    }
}

int main(){
    freopen("ALPHABET.INP", "r", stdin);
    freopen("ALPHABET.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    for (int k=1; k<=t; k++){
        memset(v, '.', sizeof v);
        cin>> n;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++) cin>> v[i][j];
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (v[i][j]=='.') v[i][j]=process(i, j);
            }
        }
        cout<< "Case "<< k<< ":"<< endl;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++) cout<< v[i][j];
            cout<< endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define maxn 1001
#define MOD 1000000007
using namespace std;

long long F[maxn][maxn];
int n;

void solution(){
    // F[i][j] la to hop chap j cua i
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j==0 || i==j){
                F[i][j]=1;
            } else{
                F[i][j]=F[i-1][j-1]+F[i-1][j];
                F[i][j]%=MOD;
            }
        }
    }
}

int main(){
    cin>> n;
    solution();
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout<< F[i][j]<< " ";
        }
        cout<< endl;
    }
}

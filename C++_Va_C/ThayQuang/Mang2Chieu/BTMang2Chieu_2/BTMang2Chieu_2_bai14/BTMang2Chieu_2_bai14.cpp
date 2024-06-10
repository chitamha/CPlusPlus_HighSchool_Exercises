#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int A[10000][10000];
void nhapMang(int n, int m, int A[][10000]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
}

void sapXep(int n, int m, int A[][10000], int B[]){
    int cnt=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            B[cnt]=A[i][j];
            cnt++;
        }
    }
    sort(B, B+cnt);
    cnt=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            A[i][j]=B[cnt];
            ++cnt;
        }
    }
}

int main(){
    freopen("SAPXEP.INP", "r", stdin);
    freopen("SAPXEP.OUT", "w", stdout);
    cin>> n>> m;
    int B[n*m];
    nhapMang(n, m, A);
    sapXep(n, m, A, B);
    int C[10000][10000];
    int c1=0, c2=n-1, h1=0, h2=n-1;
    while(c1<=c2){
        if (c1%2==0){
            for (int i=0; i<h1; i++){
                C[i][c1]=A[h1][i];
            }
            ++c1;
        } else{
            for (int i=h1-1; i>=0; i--){
                C[i][c1]=A[h1][i];
            }
            ++c1;
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n;j++){
            cout<< C[i][j]<< " ";
        }
        cout<< endl;
    }
}

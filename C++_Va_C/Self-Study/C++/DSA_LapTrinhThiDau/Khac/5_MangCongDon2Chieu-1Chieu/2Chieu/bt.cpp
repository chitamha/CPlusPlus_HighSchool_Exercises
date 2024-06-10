#include <iostream>
using namespace std;
int main(){
    int n, q;
    cin>> n>> q;
    char A[n][n];
    int B[n][n];
    int pre[n+1][n+1];
    for (int i=0; i<=n; i++){
        pre[i][0]=0;
        pre[0][i]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
            if (A[i][j]=='*'){
                B[i][j]=1;
            } else B[i][j]=0;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+B[i][j];
        }
    }
    while (q--){
        int sum=0;
        int x1, x2, y1, y2;
        cin>> x1>> y1>> x2>> y2;
        cout<< pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1];
        /*for (int i=x1; i<=x2; i++){
            for (int j=y1; j<=y2; j++){
                sum+=B[i][j];
            }
        }
        cout<< endl<< sum;*/
        cout<< endl;
    }
}

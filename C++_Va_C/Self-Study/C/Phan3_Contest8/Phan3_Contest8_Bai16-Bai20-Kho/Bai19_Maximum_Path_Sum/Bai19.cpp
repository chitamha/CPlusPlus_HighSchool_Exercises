#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int main()
{
    cin>> n>> m;
    int A[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    int res[n][m];
    /*
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 && j==0){
                res[0][0]=A[0][0];
            }
            else if(i==0){
                res[i][j]=A[i][j]+res[i][j-1];
            }
            else if(j==0){
                res[i][j]=A[i][j]+res[i-1][j];
            }
            else if(A[i-1][j]>=A[i][j-1]){
                res[i][j]=res[i-1][j]+A[i][j];
            }
            else res[i][j]=res[i][j-1]+A[i][j];
        }
    }
    */
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            res[i][j]=A[i][j];
            if (i==0 && j==0){
                res[i][j]=A[i][j];
            }
            else if(i==0){
                res[i][j]+=res[i][j-1];
            }
            else if(j==0){
                res[i][j]+=res[i-1][j];
            }
            else res[i][j]+=fmax(res[i][j-1], res[i-1][j]);
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< res[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< res[n-1][m-1];
    return 0;
}

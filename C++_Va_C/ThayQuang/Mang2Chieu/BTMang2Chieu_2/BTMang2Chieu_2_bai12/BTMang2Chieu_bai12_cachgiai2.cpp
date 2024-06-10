#include <iostream>
using namespace std;
int n, m, dem=1;
int main(){
    cin>> n>> m;
    int A[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            A[i][j]=dem;
            dem++;
            if (j==m-1){
                    i++;
                for (int k=m-1; k>=0; k--){
                    A[i][k]=dem;
                    dem++;
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}

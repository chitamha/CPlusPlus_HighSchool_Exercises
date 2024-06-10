#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n][m];
    int h1=0, h2=n-1, c1=0, c2=m-1, dem=1;
    while (h1<=h2){
        for (int i=c1; i<=c2; i++){
            A[h1][i]=dem;
            dem++;
        }
        h1++;
        for (int i=c2; i>=0; i--){
            A[h1][i]=dem;
            dem++;
        }
        h1++;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}

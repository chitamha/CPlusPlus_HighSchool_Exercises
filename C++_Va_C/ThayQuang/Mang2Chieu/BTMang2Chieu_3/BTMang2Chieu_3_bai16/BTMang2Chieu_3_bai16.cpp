#include <iostream>
using namespace std;
int main(){
    freopen("RECTANGLE.INP", "r", stdin);
    freopen("RECTANGLE.OUT", "w", stdout);
    int dem=1;
    int m, n;
    cin>> m>> n;
    int A[m][n];
    int h1=0, hn=m-1, c1=0, cn=n-1;
    while(h1<=hn){
        for (int i=c1; i<=cn; i++){
            A[hn][i]=dem;
            dem++;
        }
        --hn;
        for (int i=cn; i>=c1; i--){
            A[hn][i]=dem;
            dem++;
        }
        --hn;
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}

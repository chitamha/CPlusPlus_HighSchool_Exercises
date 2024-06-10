#include <iostream>
#include <math.h>
using namespace std;
int main(){
    freopen("TongHangMax.inp", "r", stdin);
    freopen("TongHangMax.out", "w", stdout);
    int m, n;
    cin>> m>> n;
    int A[m][n], B[m];
    int sum, gtln;
    for (int i=0; i<m; i++){
        sum=0;
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            sum+=A[i][j];
        }
        if (i==0) gtln=sum;
        gtln=fmax(gtln, sum);
        B[i]=sum;
    }
    cout<< "Tong lon nhat: "<< gtln<< endl;
    for (int i=0; i<m; i++){
        if (gtln==B[i]){
            cout<< "Hang thu: "<< i+1<< endl;
        }
    }
}

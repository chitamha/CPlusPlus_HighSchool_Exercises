#include <iostream>
#include <algorithm>
bool ktsL(int n){
    if (n%2==1){
        return 1;
    }
    return 0;
}

using namespace std;
int main(){
    freopen("TongHangLe.inp", "r", stdin);
    freopen("TongHangLe.out", "w", stdout);
    int m, n;
    cin>> m>> n;
    int A[m][n], B[m];
    int sum;
    for (int i=0; i<m; i++){
        sum=0;
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            if (ktsL(A[i][j])) sum+=A[i][j];
        }
        if (i==0) cout<< "Tong cua 5 hang"<< endl;
        cout<< "Tong hang thu "<< i+1<< " = "<< sum<< endl;
        B[i]=sum;
    }
    sort(B, B+m, greater<int>());
    cout<< "Tong cac so giam dan: ";
    for (int i=0; i<m; i++){
        cout<< B[i]<< " ";
    }
}

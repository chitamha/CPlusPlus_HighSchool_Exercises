#include <iostream>
#include <math.h>
using namespace std;
int m, n;
int main(){
    cin>> m>> n;
    int A[m][n];
    int max=-110;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            max=fmax(A[i][j], max);
        }
    }
    cout<< max<< endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (A[i][j]==max)
                cout<< "Vi tri xuat hien : A["<< i+1<< "]["<< j+1<< "]"<< endl;
        }
    }
    return 0;
}

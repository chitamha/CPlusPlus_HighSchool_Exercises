#include <iostream>
using namespace std;
int m, n;
int main(){
    cin>> m>> n;
    int A[502][502];
    for (int i=0; i<502; i++){
        for (int j=0; j<502; j++){
            A[i][j]=0;
        }
    }
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++){
            cin>> A[i][j];
        }
    }
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++){
            cout<< A[i-1][j-1]+A[i-1][j]+A[i-1][j+1]+A[i][j-1]+A[i][j]+A[i][j+1]+A[i+1][j-1]+A[i+1][j]+A[i+1][j+1]<< " ";
        }
        cout<< endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int n, m;
int main(){
    cin>> n>> m;
    int A[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    cout<< "Pattern 1"<< endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<< A[j][i]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 2"<< endl;
    for (int i=n-1; i>=0; i--){
        for (int j=m-1; j>=0; j--){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 3"<< endl;
    for (int i=m-1; i>=0; i--){
        for (int j=0; j<n; j++){
            cout<< A[j][i]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 4"<< endl;
    for (int i=0; i<n; i++){
        for (int j=m-1; j>=0; j--){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}

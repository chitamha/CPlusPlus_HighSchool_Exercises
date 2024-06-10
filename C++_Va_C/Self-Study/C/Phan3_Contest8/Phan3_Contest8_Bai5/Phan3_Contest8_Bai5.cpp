#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    cout<< "Pattern 1"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< A[j][i]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 2"<< endl;
    for (int i=n-1; i>=0; i--){
        for (int j=n-1; j>=0; j--){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 3"<< endl;
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<n; j++){
            cout<< A[j][i]<< " ";
        }
        cout<< endl;
    }
    cout<< "Pattern 4"<< endl;
    for (int i=0; i<n; i++){
        for (int j=n-1; j>=0; j--){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}

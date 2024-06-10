#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[102][102];
    for (int i=0; i<102; i++){
        for (int j=0; j<102; j++){
            A[i][j]=0;
        }
    }
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            cin>> A[i][j];
        }
    }
    cout<< n<< endl;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            int sum=0;
            //cout<< A[i-1][j]+A[i][j-1]+A[i+1][j]+A[i][j+1]+A[i][j]<< " ";
            for (int h=i-1; h<=i+1; h++){
                for (int k=j-1; k<=j+1; k++){
                    sum+=A[h][k];
                }
            }
            cout<< sum-A[i-1][j-1]-A[i+1][j+1]-A[i+1][j-1]-A[i-1][j+1]<< " ";
        }
        cout<< endl;
    }
    return 0;
}

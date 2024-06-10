#include <iostream>
using namespace std;
int A[1001][1001];
int main(){
    int M, N;
    cin>> M >> N;
    for (int i=0; i<M+1; i++){
        A[0][i]=0;
        A[i][0]=0;
    }
    for (int i=1; i<M+1; i++){
        for (int j=1; j<N+1; j++){
            cin>> A[i][j];
        }
    }
    int warshipCount=0;
    for (int i=1; i<M+1; i++){
        for (int j=1; j<N+1; j++){
            if (A[i][j]==1 && A[i-1][j]==0 && A[i][j-1]==0){
                warshipCount++;
            }
        }
    }
    cout<< warshipCount;
}

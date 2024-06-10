#include <iostream>
#include <algorithm>
using namespace std;
int n;
int A[1000][1000];
bool check(int i, int k){
    if (k==0) return 1;
    else
    {
        for (int j=0; j<k; j++){
            if (A[i][j]==A[i][k])
                return 0;
        }
        return 1;
    }
}
int chua[1000000];
void mangChua(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (check(i, j)){
                chua[A[i][j]]+=1;
            }
        }
    }
}
int cnt=0;
void mangMoi(int B[]){
    for (int i=0; i<1000000; i++){
        if (chua[i]==n){
            B[cnt]=i;
            cnt++;
        }
    }
    sort(B, B+cnt);
}

int main(){
    cin>> n;
    int B[n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    mangChua();
    mangMoi(B);
    if (cnt!=0){
        for (int i=0; i<cnt; i++){
            cout<< B[i]<< " ";
        }
    } else cout<< "NOT FOUND";
    return 0;
}

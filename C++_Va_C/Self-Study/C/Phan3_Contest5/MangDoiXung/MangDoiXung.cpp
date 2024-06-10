#include <iostream>
using namespace std;
bool check(int A[], int n){
    int l=0; int r=n-1;
    while(l<=r) {
        if (A[l]!=A[r]){
            return 0;
        }
        ++l; --r;
    }
    return 1;
}
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }/*
    bool check=false;
    for (int i=0; i<n/2; i++){
        if ((A[i]!=A[n-1-i])||(i>=n-1-i)){
            check=false;
            break;
        } else {
        check=true;
        }
    }
    if (check){
        cout<< "Day doi xung";
    } else{
    cout<< "Khong phai day doi xung";
    }*/
    if (check(A, n)){
        cout<< "YES";
    } else{
    cout<< "NO";
    }
}

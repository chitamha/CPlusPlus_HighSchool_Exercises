#include <iostream>
using namespace std;
int gThua(int n){
    int tich=1;
    for (int i=1; i<=n; i++){
        tich*=i;
    }
    return tich;
}
int n, kq=0, dem=0;
int main(){
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n; i++){
        for (int j=1; j<n; j++){
            if (A[i]==A[j]){
                dem+=1;
            }
        }
        kq+=(gThua(dem))/(2*gThua(dem-2));
        dem=0;
    }
    cout<< kq;
}

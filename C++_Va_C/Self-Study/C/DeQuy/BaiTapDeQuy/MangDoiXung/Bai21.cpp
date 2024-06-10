#include <iostream>
using namespace std;
bool mangDoiXung(int A[], int l, int r){
    if (A[l]!=A[r]){
        return 0;
    }
    else{
        l++, r--;
        if (l>=r){
            return 1;
        }
        return mangDoiXung(A, l, r);
    }
}
int main(){
    int n;
    cin>> n;
    int l=0, r=n-1;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    if (mangDoiXung(A, l, r)) cout<< "YES";
    else cout<< "NO";
}

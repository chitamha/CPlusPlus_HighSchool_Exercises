#include <iostream>
using namespace std;
bool check(int A[], int n){
    if (n==1) return 1;
    else
    {
        if (A[n-1]<A[n-2]) return 0;
        else {
            return check(A, n-1);
        }
    }
}
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    if (check(A, n)) cout<< "YES";
    else cout<< "NO";
}

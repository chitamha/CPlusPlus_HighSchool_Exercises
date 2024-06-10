#include <iostream>
using namespace std;
int A[500];
int n;
int main(){
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=n-1; i>=0; i--){
        cout<< A[i]<< " ";
    }
}

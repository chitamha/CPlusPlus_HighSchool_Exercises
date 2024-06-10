#include <iostream>
using namespace std;
int main(){
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n-1; i++){
        int min_pos=i;
        for (int j=i+1; j<n; j++){
            if (A[j]<A[min_pos]){ // > thi sap xep giam dan, < thi sap xep tang dan
                min_pos=j;
            }
        }
        int tam=A[i]; A[i]=A[min_pos]; A[min_pos]=tam;
    }
    for (int i=0; i<n; i++){
        cout<< A[i]<< " ";
    }
}

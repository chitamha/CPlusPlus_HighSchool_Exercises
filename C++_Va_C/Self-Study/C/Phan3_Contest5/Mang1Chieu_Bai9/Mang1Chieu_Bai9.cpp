#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int dem=1, cnt=1;
    for (int i=0; i<n; i++){
        dem=1; cnt=1;
        for (int j=0; j<n; j++){
            if (A[i]==A[j]){
                dem+=1;
            }
        }
        for (int k=0; k<i; k++){
            if (A[i]==A[k]){
                ++cnt;
            }
        }
        if (cnt==1){
        cout<< A[i]<< " "<< dem-1<< endl;
        }
    }
}

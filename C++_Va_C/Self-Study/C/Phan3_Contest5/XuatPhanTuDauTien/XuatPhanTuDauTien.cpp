#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    cout<< A[0]<< " ";
    int cnt;
    for (int i=1; i<n; i++){
        cnt=0;
        for (int j=i-1; j>=0; j--){
            if (A[i]==A[j]){
                ++cnt;
            }
        }
        if (cnt==0){
            cout<< A[i]<< " ";
        }
    }
}

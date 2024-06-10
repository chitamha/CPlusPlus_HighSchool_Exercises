#include <iostream>
using namespace std;
int main(){
    int n, q;
    cin>> n>> q;
    int A[n];
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    int pre[n];
    for (int i=1; i<=n; i++){
        pre[i]=pre[i-1]+A[i];
    }
    while (q--){
        int a, b;
        cin>> a>> b;
        cout<< pre[b]-pre[a-1]<< endl;
    }
}

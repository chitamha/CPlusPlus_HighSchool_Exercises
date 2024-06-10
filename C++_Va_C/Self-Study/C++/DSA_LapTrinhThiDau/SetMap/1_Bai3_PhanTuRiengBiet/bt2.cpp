#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int DD[maxn];

int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
        DD[A[i]]++;
    }
    for (int i=0; i<n; i++){
        if (DD[A[i]]){
            cout<< A[i]<< " ";
            DD[A[i]]=0;
        }
    }
    return 0;
}

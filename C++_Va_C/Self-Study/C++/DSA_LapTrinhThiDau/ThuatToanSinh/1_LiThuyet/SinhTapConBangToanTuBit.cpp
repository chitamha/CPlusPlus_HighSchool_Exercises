#include <bits/stdc++.h>
using namespace std;

int n;
int A[105];

int main(){
    cin>> n;
    for (int i=0; i<(1<<n); i++){
        for (int j=0; j<n; j++){
            if (i&(1<<j)){
                cout<< A[j]<< " ";
            }
        }
        cout<< endl;
    }
    return 0;
}

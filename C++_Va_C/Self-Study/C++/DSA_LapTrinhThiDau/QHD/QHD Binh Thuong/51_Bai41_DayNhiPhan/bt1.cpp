#include <bits/stdc++.h>
using namespace std;

int n, m, C[45], Bit[45];

int main(){
    cin>> n>> m;
    C[0]=C[1]=1;
    for (int i=2; i<=n; i++) C[i]=C[i-1]+C[i-2];
    for (int i=1; i<=n; i++){
        if (m>C[n-i]){
            Bit[i]=1;
            m-=C[n-i];
        } else Bit[i]=0;
    }
    for (int i=1; i<=n; i++) cout<< Bit[i];
    return 0;
}

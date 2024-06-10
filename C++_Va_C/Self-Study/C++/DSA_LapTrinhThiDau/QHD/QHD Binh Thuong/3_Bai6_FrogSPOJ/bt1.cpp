#include <bits/stdc++.h>
#define maxn 100002
using namespace std;

long long n;
vector<long long> F(maxn, 0);

int main(){
    cin>> n;
    F[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=3; j++){
            if (i-j>=0){
                F[i]+=F[i-j];
            }
        }
    }
    cout<< F[n];
}

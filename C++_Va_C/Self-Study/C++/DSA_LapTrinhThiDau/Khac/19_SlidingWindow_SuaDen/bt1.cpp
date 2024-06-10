#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, k, b, Max;
vector<int> B(maxn, 1);

int main(){
    cin>> n>> k>> b;
    for (int i=1; i<=b; i++){
        int tam;
        cin>> tam;
        B[tam]=0;
    }
    for (int i=1; i<=k; i++){
        Max+=B[i];
    }
    int tam=Max;
    for (int i=k; i<=n; i++){
        if (B[i]==1){
            tam++;
        }
        if (B[i-k+1]==1){
            tam--;
        }
        Max=max(tam, Max);
    }
    cout<< k-Max;
}

#include <bits/stdc++.h>
using namespace std;

int n, k, idex, sum=0;
vector<int> v;

int main(){
    cin>> n>> k;
    v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i];
    for (int i=1; i<=k; i++) sum+=v[i];
    int Max=-1e9;
    for (int i=1; i<=n-k+1; i++){
        if (Max<sum){
            idex=i;
            Max=sum;
        }
        sum-=v[i];
        sum+=v[k+i];
    }
    cout<< Max<< endl;
    for (int i=0; i<k; i++)
        cout<< v[i+idex]<< " ";
    return 0;
}

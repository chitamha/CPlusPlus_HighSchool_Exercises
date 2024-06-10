#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

long long A[maxn], slW[maxn];
int t, n, k, vt, maxx;

int main(){
    cin>> t;
    while (t--){
        memset(slW, 0, sizeof slW);
        cin>> n>> k;
        for (int i=0; i<n; i++){
            cin>> A[i];
        }
        for (int i=0; i<k; i++){
            slW[0]+=A[i];
        }
        maxx=slW[0];
        for (int i=1; i<=n-k; i++){
            slW[i]=slW[i-1]+A[i+k-1]-A[i-1];
            if (slW[i]>maxx){
                maxx=slW[i];
                vt=i;
            }
        }
        cout<< maxx<< endl;
        for (int i=vt; i<k+vt; i++){
            cout<< A[i]<< " ";
        }
        cout<< endl;
    }
}

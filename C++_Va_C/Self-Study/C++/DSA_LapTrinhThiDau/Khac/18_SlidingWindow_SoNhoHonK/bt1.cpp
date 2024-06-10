#include <bits/stdc++.h>
#define maxn 10000001
using namespace std;

long long t, n, k, A[maxn];

int main(){
    cin>> t;
    while (t--){
        int dem1=0, dem2=0, maxx;
        cin>> n>> k;
        for (int i=0; i<n; i++){
            cin>> A[i];
            if (A[i]<=k){
                dem1++;
            }
        }
        for (int i=0; i<dem1; i++){
            if (A[i]<=k){
                dem2++;
            }
        }
        maxx=dem2;
        for (int i=dem1; i<n; i++){
            if (A[i-dem1]<=k){
                dem2--;
            }
            if (A[i+1]<=k){
                dem2++;
            }
            maxx=max(dem2, maxx);
        }
        cout<< dem1-maxx<< endl;
    }
}

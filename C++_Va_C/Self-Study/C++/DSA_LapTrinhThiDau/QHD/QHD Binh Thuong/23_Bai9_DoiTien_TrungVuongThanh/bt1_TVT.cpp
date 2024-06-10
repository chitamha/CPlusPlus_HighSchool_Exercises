#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, S;
    cin>> n>> S;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>> v[i];
    int F[S+1];
    int SL[n];
    memset(F, 62, sizeof F);
    memset(SL, 0, sizeof SL);
    F[0]=0;
    for (int i=0; i<n; i++){
        for (int j=v[i]; j<=S; j++){
            F[j]=min(F[j], F[j-v[i]]+1);
        }
    }
    cout<< F[S]<< endl;
    //Truy vết
    int j=S, i=0;
    while (j>0 && i<n){
        for (int k=j/v[i]; k>0; k--){
            if (F[j-k*v[i]]+k==F[j]){
                SL[i]=k;
                j-=k*v[i];
                break;
            }
        }
        i++;
    }
    for (int i=0; i<n; i++)
        cout<< SL[i]<< " ";
    return 0;
}

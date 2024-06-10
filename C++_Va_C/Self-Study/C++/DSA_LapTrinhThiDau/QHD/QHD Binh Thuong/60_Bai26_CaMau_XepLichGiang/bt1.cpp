#include <bits/stdc++.h>
using namespace std;

int n, L, c, A[1005], pS[1005], Cnt[1005], F[1005];

int main(){
    cin>> n>> L>> c;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        pS[i]=pS[i-1]+A[i];
    }
    for (int i=1; i<=n; i++) cout<< pS[i]<< " ";
    cout<< endl;
    memset(F, 62, sizeof F);
    F[0]=0, Cnt[0]=0;
    for (int i=1; i<=n; i++){
        for (int j=i; j>=0; j--){
            int tmp=L-(pS[i]-pS[j]), cp=0;
            if (tmp<0) break;
            if (tmp==0) cp=0;
            else if (tmp>=1 && tmp<=10) cp=-c;
            else if (tmp>10) cp=(tmp-10)*(tmp-10);
            if (F[i]>F[j]+cp){
                F[i]=F[j]+cp;
                Cnt[i]=Cnt[j]+1;
            }
        }
    }
    cout<< Cnt[n]<< " "<< F[n]<< endl;
    return 0;
}

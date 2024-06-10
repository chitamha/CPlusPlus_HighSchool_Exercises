#include <bits/stdc++.h>
#define maxn 25
using namespace std;

int n, h, T[maxn], M[maxn], D[maxn], C[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> h;
    for (int i=1; i<=n-1; i++){
        cin>> T[i];
        T[i]=T[i]/5+T[i-1];
    }
    for (int i=1; i<=n; i++) cin>> M[i];
    for (int i=1; i<=n; i++) cin>> D[i];
    //Giai
    h=h*12;
    int Max=0, ca;
    for (int i=1; i<=n; i++){
        ca=0;
        int tim=h-T[i-1];
        for (int j=1; j<=i; j++) C[j]=M[j];
        for (int k=1; k<=tim; k++){
            int jm=1;
            for (int j=2; j<=i; j++)
                if (C[j]>C[jm]) jm=j;
            if (C[jm]>0){
                ca+=C[jm];
                C[jm]-=D[jm];
            } else break;
        }
        if (Max<ca) Max=ca;
    }
    cout<< Max;
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

double disn, V, C, P, F[105];
int n;
pair<double, double> Tram[105];

int main(){
    cin>> disn;
    cin>> V>> C>> P;
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> Tram[i].fi>> Tram[i].se;
        F[i]=1000000000.0;
    }
    Tram[n+1]={disn, 0};
    F[n+1]=1000000000.0;
    for (int i=1; i<=n+1; i++){
        for (int j=i-1; j>=0; j--){
            if (Tram[i].fi-Tram[j].fi<=V/2*C)
                F[i]=min(F[i], F[j]+Tram[i].se*(Tram[i].fi-Tram[j].fi)/(C*100)+2);
            else break;
        }
    }
    cout<< F[n+1]+P;
    return 0;
}

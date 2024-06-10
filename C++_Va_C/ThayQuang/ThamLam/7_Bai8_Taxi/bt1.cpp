#include <bits/stdc++.h>
using namespace std;

int n;
int DD[10];

int main(){
    freopen("TAXI.INP", "r", stdin);
    freopen("TAXI.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    for (int i=0; i<n; i++){
        int x; cin>> x;
        DD[x]++;
    }
    int ans=DD[4]+min(DD[3], DD[1])+DD[2]/2;
    if (DD[2]%2==1) DD[2]=1;
    else DD[2]=0;
    if (DD[3]>DD[1]){
        ans+=DD[3]-DD[1];
        if (DD[2]==1) ans++;
    }
    else if (DD[3]<DD[1]){
        DD[1]=DD[1]-DD[3];
        if (DD[2]==1){
            ans++;
            DD[1]-=2;
        }
        ans+=DD[1]/4;
        DD[1]%=4;
        if (DD[1]!=0) ans++;
    }
    cout<< ans;
    return 0;
}

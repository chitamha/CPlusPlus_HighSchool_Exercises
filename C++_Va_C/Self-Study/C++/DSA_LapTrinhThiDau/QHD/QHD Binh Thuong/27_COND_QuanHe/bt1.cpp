#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10006
#define MOD 5000000
using namespace std;

/*
2: 3
3: 13
4: 75
5: 541
6: 4683
7: 47293
8: 545835
9: 7087261
10: 102247563
*/

int n;
ll F[15], gt[15];

ll ckn(int k, int n){
    return gt[n]/(gt[k]*gt[n-k]);
}

int main(){
    F[0]=F[1]=1; F[2]=3; F[3]=13;
    gt[0]=1;
    for (int i=1; i<=10; i++) gt[i]=gt[i-1]*i;
    for (int i=4; i<=10; i++){
        for (int j=1; j<i; j++){
            F[i]+=F[j]*ckn(j, i);
        }
    }
    while (cin>> n && n!=-1) cout<< F[n]<< "\n";
    return 0;
}

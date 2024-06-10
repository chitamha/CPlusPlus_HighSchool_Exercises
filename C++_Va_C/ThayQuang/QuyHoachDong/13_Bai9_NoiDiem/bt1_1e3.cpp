#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int n;
vector<int> A;
int F[maxn], before[maxn];

int main(){
    //freopen("NOIDIEM.INP", "r", stdin);
    //freopen("NOIDIEM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A.resize(n+1, 0);
    for (int i=1; i<=n; i++) cin>> A[i];
    int en=1;
    for (int i=1; i<=n; i++){
        F[i]=1;
        for (int j=1; j<i; j++){
            if (A[i]>A[j] && F[i]<F[j]+1){
                F[i]=F[j]+1;
                before[i]=j;
            }
        }
        if (F[en]<F[i]) en=i;
    }
    cout<< F[en]<< endl;
    vector<int> vet;
    while (en>0){
        vet.push_back(en);
        en=before[en];
    }
    for (int i=vet.size()-1; i>=0; i--){
        cout<< A[vet[i]]<< " "<< vet[i]<< endl;
    }
    return 0;
}

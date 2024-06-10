#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, x, y, cnt=0, vet[1000006];
vector<pair<int, int>> A;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.se<b.se;
}

int main(){
    cin>> n>> x>> y;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i].fi>> A[i].se;
    sort(A.begin()+1, A.begin()+n+1, cmp);
    //for (int i=1; i<=n; i++) cout<< A[i].fi<< " "<< A[i].se<< endl;
    int k=1, v=x;
    while (v<y){
        for (int j=n; j>=k; j--){
            if (v>=A[j].fi && v<=A[j].se){
                vet[++cnt]=j;
                v=A[j].se;
                k=j+1;
                break;
            }
        }
    }
    cout<< cnt<< endl;
    //for (int i=1; i<=cnt; i++) cout<< A[vet[i]].fi<< " "<< A[vet[i]].se<< endl;
    return 0;
}

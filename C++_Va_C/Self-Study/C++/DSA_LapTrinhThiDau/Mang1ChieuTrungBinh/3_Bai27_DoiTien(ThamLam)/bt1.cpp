#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long F[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    for (int i=0; i<=maxn; i++){
        F[i]=1e6;
    }
    for (int i=0; i<10; i++){
        F[A[i]]=1;
    }
    int q, n;
    cin>> q;
    set<int> se;
    se.insert(1);
    while (q--){
        cin>> n;
        se.insert(n);
        for (int i=0; i<10; i++){
            for (int j=*(se.begin()); j<=n; j++){
                if (j>=A[i] && F[j]!=1){
                    F[j]=min(F[j], F[j-A[i]]+1);
                }
            }
        }
        cout<< F[n]<< endl;
        se.erase(se.begin());
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dem1(int n, int p){
    int cnt;
    for (int i=p; i<=n; i+=p){
        int tam=i;
        while (tam%p==0){
            cnt++;
            tam/=p;
        }
    }
    return cnt;
}

int dem2(int n, int p){
    int cnt;
    for (int i=p; i<=n; i*=p){
        cnt+=n/i;
    }
    return cnt;
}
int main(){
    int t;
    cin>> t;
    while (t--){
        int n, p, cnt=0;
        cin>> n>> p;
        for (int i=1; i<=n; i++){
            int tmp=i;
            while (tmp%p==0){
                cnt++;
                tmp/=p;
            }
        }
        cout<< cnt<< " "<< dem1(n, p)<< " "<< dem2(n, p)<< endl;
    }
}

#include <bits/stdc++.h>
#define maxn 25
using namespace std;

int n, h, T[maxn], M[maxn], D[maxn];
vector<int> C(maxn), Save(maxn);
//C: count

int Find(int i){
    int Max=0, id=0;
    for (int k=1; k<=i; k++){
        if (M[k]-C[k]*D[k]>Max){
            Max=M[k]-C[k]*D[k];
            id=k;
        }
    }
    return id;
}

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
        C.assign(n, 0);
        ca=0;
        int tim=h-T[i-1];
        for (int j=1; j<=tim; j++){
            int id=Find(i);
            if (id==0) break;
            if (M[id]-C[id]*D[id]>0)
                ca+=M[id]-C[id]*D[id];
            C[id]++;
        }
        if (ca>Max){
            Max=ca;
            Save=C;
        }
    }
    cout<< Max<< endl;
    for (int i=1; i<=n; i++) cout<< Save[i]*5/6<< " ";
    return 0;
}

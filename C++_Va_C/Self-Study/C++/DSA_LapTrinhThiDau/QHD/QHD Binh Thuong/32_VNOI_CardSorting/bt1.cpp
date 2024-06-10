#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, c, Mang[500], ans=500;
int D[5]; //D[i]=j. Mau i co vi tri thu j
int X[5], used[5]; //Cau hinh hoan vi
vector<pair<int, int>> Nhap(500);
// (Mau, Gia tri)

void in(){
    for (int i=1; i<=c; i++) cout<< X[i]<< " ";
    cout<< endl;
}

void xuli(){
    for (int i=1; i<=c; i++) D[X[i]]=i;
    //cout<< "Mang"<< endl;
    for (int i=1; i<=c*n; i++){
        Mang[i]=D[Nhap[i].fi]*1000+Nhap[i].se;
        //cout<< Mang[i]<< " ";
    }
    //cout<< endl;
    vector<int> v;
    for (int i=1; i<=c*n; i++){
        auto it=lower_bound(v.begin(), v.end(), Mang[i]);
        if (it==v.end()) v.push_back(Mang[i]);
        else *it=Mang[i];
    }
    ans=min(ans, n*c-int(v.size()));
    v.clear();
}

void Try(int i){
    for (int j=1; j<=c; j++){
        if (used[j]) continue;
        X[i]=j;
        used[j]=1;
        if (i==c) xuli();
        else Try(i+1);
        used[j]=0;
    }
}

int main(){
    cin>> c>> n;
    for (int i=1; i<=c*n; i++)
        cin>> Nhap[i].fi>> Nhap[i].se;
    Try(1);
    cout<< ans;
    return 0;
}

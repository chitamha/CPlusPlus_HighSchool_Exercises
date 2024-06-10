#include <bits/stdc++.h>
using namespace std;

//R: 1; Y: 2; W: 3
string s;
int n, ans=0, used[4], X[4];

void inc(int &id){
    if (id<=2) id++;
    else if (id==3) id=1;
}

void xuli(){
    /*
    for (int i=1; i<=3; i++){
        char c;
        if (X[i]==1) c='R';
        else if (X[i]==2) c='Y';
        else c='W';
        cout<< c;
    }
    cout<< endl;
    */
    int id=1, del=0;
    for (int i=1; i<=n; i++){
        char c;
        if (X[id]==1) c='R';
        else if (X[id]==2) c='Y';
        else c='W';
        if (c==s[i]) inc(id);
        else del++;
    }
    ans=max(ans, n-del);
    //cout<< ans<< " "<< n-del<< endl;
}

void Try(int i){
    for (int j=1; j<=3; j++){
        if (used[j]==1) continue;
        X[i]=j;
        used[j]=1;
        if (i==3) xuli();
        else Try(i+1);
        used[j]=0;
    }
}

int main(){
    freopen("BOUGAIN.INP", "r", stdin);
    freopen("BOUGAIN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    n=s.size(); s='@'+s;
    Try(1);
    cout<< ans;
    return 0;
}

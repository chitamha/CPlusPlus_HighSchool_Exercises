#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1000006
using namespace std;

int n, Loc[maxn], cnt=0;
vector<pair<int, int>> Ans;

void xuli(int k, int pos){
    if (k==0) return;
    if (Loc[k]==pos) return xuli(k-1, pos);
    xuli(k-1, 6-pos-Loc[k]);
    cnt++;
    Ans.push_back({Loc[k], pos});
    Loc[k]=pos;
    xuli(k-1, pos);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        char c; cin>> c;
        Loc[i]=c-'A'+1;
    }
    //for (int i=1; i<=n; i++) cout<< Loc[i]<< " "; cout<< "\n";
    xuli(n, 3);
    cout<< cnt<< "\n";
    for (pair<int, int> p:Ans) cout<< char('A'+p.fi-1)<< char('A'+p.se-1)<< "\n";
    return 0;
}

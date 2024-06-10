#include <bits/stdc++.h>
#define maxn 205
using namespace std;

int n;
map<string, int> F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; cin.ignore();
    F["polycarp"]=1;
    int ma=1;
    for (int i=1; i<=n; i++){
        string a, b, c; cin>> a>> b>> c;
        for (int j=0; j<a.size(); j++) a[j]=tolower(a[j]);
        for (int j=0; j<c.size(); j++) c[j]=tolower(c[j]);
        F[a]=F[c]+1;
        ma=max(ma, F[a]);
    }
    cout<< ma;
    return 0;
}

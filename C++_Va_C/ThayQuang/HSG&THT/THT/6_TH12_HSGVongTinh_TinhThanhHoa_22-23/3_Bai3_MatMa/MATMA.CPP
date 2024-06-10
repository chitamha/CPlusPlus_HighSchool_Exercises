#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int sum=0, Dem[15];
string s;

int main(){
    freopen("MATMA.INP", "r", stdin);
    freopen("MATMA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    for (char c:s){
        Dem[c-'0']++;
        sum+=c-'0';
    }
    if (Dem[0]==0 || sum%3!=0) return cout<< -1, 0;
    else for (int i=9; i>=0; i--) cout<< string(Dem[i], '0'+i);
    return 0;
}

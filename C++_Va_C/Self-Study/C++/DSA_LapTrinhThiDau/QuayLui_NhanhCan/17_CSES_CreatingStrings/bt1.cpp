#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

string s, tmp="";
int n, used[10];
set<string> se;

void Try(int siz){
    for (int i=1; i<=n; i++){
        if (used[i]==1) continue;
        tmp=tmp+s[i];
        used[i]=1;
        if (siz==n) se.insert(tmp);
        else Try(siz+1);
        tmp.erase(tmp.end()-1);
        used[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    n=s.size(); s="@"+s;
    Try(1);
    cout<< se.size()<< endl;
    for (string x:se) cout<< x<< endl;
    return 0;
}

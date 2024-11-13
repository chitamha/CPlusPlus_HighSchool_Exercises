#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int m, n;

int process(int x, int y){
    map<int, int> mp;
    for (int i=2; i<=sqrt(x); i++){
        while (x%i==0){
            mp[i]++;
            x/=i;
        }
    }
    if (x!=1) mp[x]++;
    for (int i=2; i<=sqrt(y); i++){
        while (y%i==0){
            mp[i]--;
            y/=i;
        }
    }
    if (y!=1) mp[y]--;
    int cnt=0;
    for (auto it:mp){
        if (it.fi==2 || it.fi==3 || it.fi==5) cnt+=abs(it.se);
        else if (!(it.fi==2 || it.fi==3 || it.fi==5) && it.se!=0) return -1;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n;
    //int x; while (cin>> x) for (auto it:process(x)) cout<< it.fi<< " "<< it.se<< endl;
    cout<< process(m, n);
    return 0;
}

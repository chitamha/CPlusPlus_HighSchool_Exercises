#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;

int n, b;
bool check=false;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.fi+a.se!=b.fi+b.se) return a.fi+a.se>b.fi+b.se;
    else return a.fi<b.fi;
}

int main(){
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> b;
    priority_queue<ii, vector<ii>, decltype(cmp)*> Q(cmp);
    for (int i=0; i<n; i++){
        int P, S;
        cin>> P>> S;
        Q.push({P, S});
    }
    int cnt=0, Max=0;
    while (!Q.empty() && b>=0){
        auto top=Q.top(); Q.pop();
        if (top.fi+top.se<=b){
            cnt++;
            Max=max(Max, top.fi);
            cout<< top.fi<< " "<< top.se<< " "<< b<< endl;
            b-=top.fi+top.se;
        } else{
            if (!check){
                b+=Max/2;
                check=true;
            }
            if (top.fi+top.se<=b){
                cnt++;
                cout<< top.fi<< " "<< top.se<< " "<< b<< endl;
                b-=top.fi+top.se;
            }
        }
    }
    cout<< b<< endl;
    cout<< cnt;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, Vec[50]; ll ans=1e18, cnt=0, sum=0;
vector<ll> A, B;

void Try(int siz, int en, vector<ll> &Chua, ll sum){
    if (siz>en){
        Chua.push_back(sum);
        return;
    }
    Try(siz+1, en, Chua, sum);
    Try(siz+1, en, Chua, sum+Vec[siz]);
}

ll CountEle(ll x){
    return upper_bound(B.begin(), B.end(), x)-lower_bound(B.begin(), B.end(), x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> Vec[i], sum+=Vec[i];
    Try(1, n/2, A, 0ll);
    Try(n/2+1, n, B, 0ll);
    sort(B.begin(), B.end());
    //for (ll x:A) cout<< x<< " "; cout<< endl;
    //for (ll x:B) cout<< x<< " "; cout<< endl;
    for (ll x:A){
        //cout<< x<< endl;
        auto it=upper_bound(B.begin(), B.end(), sum/2-x); ll tmpcnt, y;
        if (it!=B.end()){
            y=*it;
            tmpcnt=CountEle(y);
            if (ans>2*(x+y)-sum){
                ans=2*(x+y)-sum;
                cnt=tmpcnt;
            } else if (ans==2*(x+y)-sum) cnt+=tmpcnt;
        //cout<< "Case 1: "<< ans<< " "<< cnt<< " "<< 2*(x+y)-sum<< " "<< tmpcnt<< " "<< min(sum-(x+y), x+y)<< " "<< max(sum-(x+y), x+y)<< endl;
        }
        /*
        if (it!=B.begin()){
            y=*(it-1);
            tmpcnt=CountEle(y);
            if (ans>sum-2*(x+y)){
                ans=sum-2*(x+y);
                cnt=tmpcnt;
            } else if (ans==sum-2*(x+y)) cnt+=tmpcnt;
        //cout<< "Case 2: "<< ans<< " "<< cnt<< " "<< sum-2*(x+y)<< " "<< tmpcnt<< " "<< min(sum-(x+y), x+y)<< " "<< max(sum-(x+y), x+y)<< endl;
        }
        */
    }
    cout<< ans<< " "<< (cnt+1)/2;
    return 0;
}

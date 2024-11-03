#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, l, r, L, U, DD[300], ans=0;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> L>> U;
    //cin.ignore();
    ll cnt=0;
    for (int i=1; i<=n; i++){
        string x; cin>> x;
        if (i>=L && i<=U) s+=x;
        if (i==L) l=cnt+1;
        cnt+=x.size();
        if (i==U) r=cnt;
    }
    //cout<< s<< " "<< l<< " "<< r<< endl;
    cnt=0;
    r=r-l; l=0;
    while (l<=r){
        if (!DD[s[l]]){
            DD[s[l]]=1;
            cnt++;
            l++;
        } else{
            ans+=(cnt+1)*cnt/2;
            cnt=1;
            memset(DD, 0, sizeof DD);
            DD[s[l]]=1;
            l++;
        }
        cout<< s[l-1]<< " "<< cnt<< " "<< ans<< endl;
    }
    cout<< ans+cnt*(cnt+1)/2;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, m, ans=0, X[15];
vector<ll> A;

ll cnt=0;

void xuli(){
    ll tmpans=0;
    X[0]=1;
    /*
    cout<< ++cnt<< ": "<< A[1];
    for (int i=2; i<=n; i++){
        if (X[i-1]==1) cout<< "+"<< A[i];
        else if (X[i-1]==2) cout<< "-"<< A[i];
        else if (X[i-1]==3) cout<< "*"<< A[i];
    }
    cout<< "\n";
    */
    stack<pair<int, int>> st;
    for (int i=1; i<=n; i++){
        if (X[i-1]==3){
            pair<int, int> tmp;
            if (!st.empty()){
                tmp=st.top();
                st.pop();
            } else{
                tmp.fi=1;
                tmp.se=X[i-1];
            }
            st.push({(tmp.fi*(A[i]%m))%m, tmp.se});
        } else st.push({A[i], X[i-1]});
    }
    while (!st.empty()){
        if (st.top().se==1) tmpans=(tmpans+st.top().fi%m)%m;
        else tmpans=(tmpans-st.top().fi%m)%m;
        st.pop();
    }
    //cout<< tmpans<< "\n";
    ans+=tmpans%m==0;
}

void Try(ll i){
    //1: +; 2: -; 3: *
    for (ll j=1; j<=3; j++){
        X[i]=j;
        if (i==n-1) xuli();
        else Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        cin>> n>> m;
        A.resize(n+1); ans=0;
        for (ll i=1; i<=n; i++) cin>> A[i];
        Try(1);
        cout<< ans<< "\n";
        A.clear();
    }
    return 0;
}

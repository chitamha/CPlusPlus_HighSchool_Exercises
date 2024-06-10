#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1006
using namespace std;

int n, m, A[maxn][maxn], h[maxn], ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int x; cin>> x;
            if (x==1) h[j]++;
            else h[j]=0;
        }
        deque<int> dq;
        vector<int> L(m+5, 0);
        vector<int> R(m+5, 0);
        for (int i=1; i<=m; i++){
            while (!dq.empty() && h[dq.back()]>=h[i]) dq.pop_back();
            if (!dq.empty()) L[i]=dq.back()+1;
            else L[i]=1;
            dq.push_back(i);
        }
        dq.clear(); //Dễ sai vì thiếu
        for (int i=m; i>=1; i--){
            while (!dq.empty() && h[dq.back()]>=h[i]) dq.pop_back();
            if (!dq.empty()) R[i]=dq.back()-1;
            else R[i]=m;
            dq.push_back(i);
        }
        for (int i=1; i<=m; i++){
            //cout<< L[i]<< " "<< R[i]<< " "<< h[i]<< endl;
            ans=max(ans, (R[i]-L[i]+1)*h[i]);
        }
    }
    cout<< ans;
    return 0;
}

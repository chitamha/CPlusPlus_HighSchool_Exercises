#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
string Str[5]={"", "stack", "queue", "priority_queue", ""};
stack<int> st;
queue<int> q;
priority_queue<int> pq;
vector<int> Abi(5, 1);

int main(){
    freopen("DATA.INP", "r", stdin);
    freopen("DATA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin>> n){
        for (int i=1; i<=n; i++){
            int k, x; cin>> k>> x;
            if (k==1){
                st.push(x);
                q.push(x);
                pq.push(x);
            }
            else {
                if (!st.empty()){
                    if (x!=st.top()) Abi[1]=0;
                    else st.pop();
                } else Abi[1]=0;
                if (!q.empty()){
                    if (x!=q.front()) Abi[2]=0;
                    else q.pop();
                } else Abi[2]=0;
                if (!pq.empty()){
                    if (x!=pq.top()) Abi[3]=0;
                    else pq.pop();
                } else Abi[3]=0;
            }
        }
        int cnt=0; string ans="";
        for (int i=1; i<=3; i++){
            if (Abi[i]==1){
                cnt++;
                ans=Str[i];
            }
        }
        if (cnt==0) cout<< "impossible"<< endl;
        if (cnt==1) cout<< ans<< endl;
        if (cnt>=2) cout<< "no sure"<< endl;
        while (!st.empty()) st.pop();
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        for (int i=1; i<=3; i++) Abi[i]=1;
    }
    return 0;
}

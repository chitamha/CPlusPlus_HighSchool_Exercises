#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
string S[5]={"", "stack", "queue", "priority_queue", ""};
vector<int> Abi(5);
vector<pair<int, int>> Tv;
multiset<int> mse;

/*
1: stack
2: queue
3: priority_queue
*/

void process(){
    int previous=1e9;
    deque<int> dq;
    for (int i=0; i<n; i++){
        if (Tv[i].fi==1){
            dq.push_back(Tv[i].se);
            mse.insert(Tv[i].se);
        }
        else {
            if (dq.empty() || mse.count(Tv[i].se)==0){
                cout<< "impossible"<< endl;
                return;
            }
            if (Tv[i].se!=dq.front() && Tv[i].se!=dq.back()) Abi[1]=Abi[2]=0;
            if (previous<Tv[i].se) Abi[3]=0;
            if (dq.size()>=2){
                if (Tv[i].se==dq.front()){
                    Abi[1]=0;
                    dq.pop_front();
                }
                else {
                    Abi[2]=0;
                    dq.pop_back();
                }
            }
            else dq.pop_back();
            previous=Tv[i].se;
            if (dq.empty()) previous=1e9;
            mse.erase(mse.find(Tv[i].se));
        }
    }
    int cnt=0;
    string ans;
    for (int i=1; i<=3; i++){
        if (Abi[i]==1){
            cnt++;
            ans=S[i];
        }
    }
    if (cnt==0) cout<< "impossible"<< endl;
    if (cnt==1) cout<< ans<< endl;
    if (cnt>=2) cout<< "no sure"<< endl;
}

int main(){
    freopen("DATA.INP", "r", stdin);
    freopen("DATA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin>> n){
        for (int i=1; i<=n; i++){
            int k, x; cin>> k>> x;
            Tv.push_back({k, x});
        }
        for (int i=1; i<=3; i++) Abi[i]=1;
        process();
        /*
        cout<< n<< endl;
        for (pair<int, int> p:Tv) cout<< p.fi<< " "<< p.se<< endl;
        */
        Tv.clear();
        mse.clear();
    }
    return 0;
}

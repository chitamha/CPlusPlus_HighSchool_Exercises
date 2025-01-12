#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, A[100005];

int main(){
    freopen("TRAIN1.INP", "r", stdin);
    freopen("TRAIN1.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    deque<int> Dq;
    for (int i=1; i<=n; i++) cin>> A[i];
    int id=1, a=1;
    vector<pair<int, int>> Vet;
    while (id<=n){
        if (a<=n && A[id]==a){
            Vet.push_back({1, 3});
            a++; id++;
        } else if (!Dq.empty() && A[id]==Dq.front()){
            Vet.push_back({2, 3});
            Dq.pop_front(); id++;
        }
        if (a<=n && !Dq.empty() && A[id]<a && A[id]!=Dq.front()) return cout<< "NO", 0;
        if (a<=n && Dq.empty() && A[id]<a) return cout<< "NO", 0;
        if (a>n && !Dq.empty() && A[id]!=Dq.front()) return cout<< "NO", 0;
        while (a<=n && A[id]>a){
            Dq.push_back(a); a++;
            Vet.push_back({1, 2});
        }
    }
    cout<< "YES"<< endl;
    for (auto p:Vet) cout<< char(64+p.fi)<< "->"<< char(64+p.se)<< endl;
    return 0;
}

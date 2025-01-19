#include <bits/stdc++.h>
using namespace std;

int n, cnt=0;
deque<int> dq;

int main(){
    freopen("RECARD.INP", "r", stdin);
    freopen("RECARD.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin>> n){
        for (int i=1; i<=n; i++) dq.push_back(i);
        while (dq.size()>1){
            cout<< dq.front()<< " ";
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout<< endl<< dq.front()<< endl;
        dq.clear();
    }
    return 0;
}

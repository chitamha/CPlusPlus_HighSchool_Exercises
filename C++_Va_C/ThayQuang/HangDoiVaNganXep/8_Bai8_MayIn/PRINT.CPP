#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, pos, ans=0;
deque<pair<int, int>> A;
deque<int> Inc;
vector<int> tmp;

int main(){
    freopen("PRINT.INP", "r", stdin);
    freopen("PRINT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
        cin>> n>> pos;
        ans=0;
        for (int i=0; i<n; i++){
            int x; cin>> x;
            if (i==pos) A.push_back({x, 1});
            else A.push_back({x, 0});
            tmp.push_back(x);
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        for (int x:tmp) Inc.push_back(x);
        while (true){
            if (A.front().se==1 && A.front().fi==Inc.front()) break;
            if (A.front().fi==Inc.front()){
                ans+=60;
                A.pop_front();
                Inc.pop_front();
            }
            else {
                A.push_back(A.front());
                A.pop_front();
                ans++;
            }
        }
        cout<< (ans+60)/60<< " "<< (ans+60)%60<< endl;
        A.clear(); Inc.clear(); tmp.clear();
    }
    return 0;
}

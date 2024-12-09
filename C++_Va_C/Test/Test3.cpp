#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    multiset<int> se={1, 2, 2, 1, 4, 5, 4};
    for (int x:se) cout<< x<< " "; cout<< endl;
    auto it=se.lower_bound(2);
    se.erase(it);
    it++;
    se.erase(it);
    for (int x:se) cout<< x<< " ";
    return 0;
}

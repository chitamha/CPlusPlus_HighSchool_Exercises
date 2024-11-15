#include <bits/stdc++.h>
#define maxn 1000006
#define fi first
#define se second
using namespace std;

int n, k, Q;

struct point{
    int toado, style;
    //0: mo; -1: dong
    friend bool operator < (point A, point B){
        return A.toado<B.toado;
    }
};
vector<point> Sol;

bool cnp(pair<int, int> A, pair<int, int> B){
    return A.fi<B.fi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k>> Q;
    for (int i=1; i<=k; i++){
        int x, y; cin>> x>> y;
        Sol.push_back({x, 0});
        Sol.push_back({y+1, -1});
    }
    for (int i=1; i<=Q; i++){
        int toado; cin>> toado;
        Sol.push_back({toado, i});
    }
    sort(Sol.begin(), Sol.end());
    n=Sol.size();
    vector<pair<int, int>> Ans;
    int cnt=0;
    for (int i=0; i<n; i++){
        if (Sol[i].style==0) cnt++;
        else if (Sol[i].style==-1) cnt--;
        else Ans.push_back({Sol[i].style, cnt});
    }
    sort(Ans.begin(), Ans.end());
    for (auto x:Ans) cout<< x.se<< endl;
    return 0;
}
/*
Input:
10 2 2
3 5
8 8
7
4
Output:
0
1
*/

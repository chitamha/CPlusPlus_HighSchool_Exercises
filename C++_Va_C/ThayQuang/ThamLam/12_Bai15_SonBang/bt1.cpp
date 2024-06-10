#include <bits/stdc++.h>
using namespace std;

int m, n, r, c;

struct board{
    vector<vector<int>> v;
    int cnt;
    board(int color, int dem){
        for (int i=0; i<=m; i++){
            vector<int> tmp(n+1, color);
            v.push_back(tmp);
        }
        cnt=dem;
    }
    board(vector<vector<int>> tmp, int dem){
        v=tmp; cnt=dem;
    }
    friend bool operator < (board A, board B){
        return A.v<B.v;
    }
    friend bool operator == (board A, board B){
        return A.v==B.v;
    }
};

int solution(vector<vector<int>> Vt){
    board white(0, 0);
    board black(1, 0);
    set<board> se;
    deque<board> dq;
    dq.push_back({Vt, 0});
    se.insert({Vt, 0});
    while (!dq.empty()){
        board tmp=dq.front();
        dq.pop_front();
        se.insert(tmp);
        if (tmp.cnt>10000) return -1;
        if (tmp.v==white.v) return tmp.cnt;
        if (tmp.v==black.v) return tmp.cnt;
        for (int i=1; i<=m-r+1; i++){
            for (int j=1; j<=n-c+1; j++){
                board tmp2=tmp;
                for (int i1=i; i1<=i+r-1; i1++){
                    for (int j1=j; j1<=j+c-1; j1++){
                        tmp2.v[i1][j1]^=1;
                    }
                }
                if (se.find(tmp2)==se.end()) dq.push_back({tmp2.v, tmp2.cnt+1});
            }
        }
    }
    return -1;
}

int main(){
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (true){
        cin>> m>> n>> r>> c;
        cin.ignore();
        if (m==0 && n==0 && r==0 && c==0) break;
        board A(0, 0);
        for (int i=1; i<=m; i++){
            string s; cin>> s;
            for (int j=0; j<s.size(); j++){
                A.v[i][j+1]=s[j]-'0';
            }
        }
        cout<< solution(A.v)<< endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int n;
multiset<int> A;

void solution(int so, int x, multiset<int> A){
    if (so==1){
        A.insert(x);
    } else if (so==2){
        if (A.find(x)!=A.end())
            A.erase(A.find(x));
    } else if (so==3){
        auto it=A.lower_bound(x);
        if (it!=A.end()) cout<< *it<< endl;
        else cout<< -1<< endl;
    } else{
        if (*(A.begin())>x) cout<< -1<< endl;
        else{
            auto it=A.upper_bound(x);
            it--;
            cout<< *it<< endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n;
    for (int i=0; i<n; i++){
        int tam; cin>> tam;
        A.insert(tam);
    }
    int q, so, x;
    cin>> q;
    while (q--){
        cin>> so>> x;
        solution(so, x, A);
    }
    return 0;
}

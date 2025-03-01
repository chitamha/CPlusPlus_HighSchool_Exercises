#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10000005
using namespace std;

int n;
queue<pair<int, int>> q;

void HaNoi(int n, int Mot, int Hai, int Ba){
    if (n==1){
        q.push({Mot, Ba});
        return;
    }
    HaNoi(n-1, Mot, Ba, Hai);
    q.push({Mot, Ba});
    HaNoi(n-1, Hai, Mot, Ba);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    HaNoi(n, 1 , 2, 3);
    cout<< q.size()<< "\n";
    while (!q.empty()){
        pair<int, int> p=q.front();
        cout<< p.first<< " "<< p.second<< "\n";
        q.pop();
    }
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10000005
using namespace std;

int n;

void HaNoi(int n, int Mot, int Hai, int Ba){
    if (n==1){
        cout<< Mot<< " "<< Ba<< "\n";
        return;
    }
    HaNoi(n-1, Mot, Ba, Hai);
    cout<< Mot<< " "<< Hai<< "\n";
    HaNoi(n-1, Hai, Mot, Ba);
    cout<< Hai<< " "<< Ba<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    HaNoi(n, 1 , 2, 3);
    return 0;
}

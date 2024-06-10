#include <bits/stdc++.h>
#define maxn 2005
using namespace std;

int t, a, b, c, d;
vector<int> prime(maxn, 1);

void sang(){
    prime[0]=prime[1]=0;
    for (int i=2; i<=sqrt(maxn); i++){
        if (prime[i]){
            for (int j=i*i; j<=maxn; j+=i)
                prime[j]=0;
        }
    }
}

bool solution(int x, int y, int m, int n){
    for (int i=x; i<=y; i++){
        int check=0;
        for (int j=m; j<=n; j++){
            if (prime[i+j]==1){
                check=1;
                break;
            }
        }
        if (check==0) return 1;
    }
    return 0;
}

int main(){
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    sang();
    cin>> t;
    while (t--){
        cin>> a>> b>> c>> d;
        if (solution(a, b, c, d)) cout<< "Tam"<< "\n";
        else cout<< "Cam"<< "\n";
    }
    return 0;
}

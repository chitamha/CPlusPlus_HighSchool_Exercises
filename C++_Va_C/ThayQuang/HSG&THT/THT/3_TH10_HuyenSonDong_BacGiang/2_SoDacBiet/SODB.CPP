#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n; int cnt=0;
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

int main(){
    freopen("SODB.INP", "r", stdin);
    freopen("SODB.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    sang();
    cin>> n;
    for (int i=2; i<=sqrt(n); i++){
        if (prime[i]==1) cnt++;
    }
    cout<< cnt;
    return 0;
}

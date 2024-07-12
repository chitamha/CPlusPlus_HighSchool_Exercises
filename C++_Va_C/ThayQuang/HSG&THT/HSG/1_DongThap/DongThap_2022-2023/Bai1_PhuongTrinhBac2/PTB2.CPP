#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, cnt=0, A[maxn];

void process(int x, int id){
    int l=1, r=id-1;
    ll sum=0;
    while (l<r){
        sum=A[l]+A[r];
        if (sum==x){
            /*
            cout<< A[l]<< " "<< x<< " "<< A[r]<< endl;
            cout<< A[r]<< " "<< x<< " "<< A[l]<< endl;
            */
            cnt+=2;
            l++; r--;
        } else if (sum>x) r--;
        else l++;
    }
}

int main(){
    freopen("PTB2.INP", "r", stdin);
    freopen("PTB2.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    sort(A+1, A+n+1);
    if (n<=3000){
        for (int i=1; i<=n; i++) process(A[i], i);
        cout<< cnt;
    } else{
        for (int i=3; i<=n; i++){
            if (i&1) cnt+=i-1;
            else cnt+=i-2;
        }
        cout<< cnt;
    }
    return 0;
}

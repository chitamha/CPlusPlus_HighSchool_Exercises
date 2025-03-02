#include <bits/stdc++.h>
#define ll long long
#define MOD 5000000
using namespace std;

ll n, k, A[10005], Bit[10005][55];
//Mod thêm trong hàm update, get mới AC
//Không thì 9/11

void update(ll pos, ll val, ll siz){
    for (; pos<=n; pos+=pos&(-pos))
        (Bit[pos][siz]+=val)%=MOD;
}

ll get(ll pos, ll siz){
    ll sum=0;
    for (; pos>=1; pos-=pos&(-pos))
        (sum+=Bit[pos][siz])%=MOD;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    vector<ll> v;
    for (ll i=1; i<=n; i++) cin>> A[i], v.push_back(A[i]); {}
    sort(v.begin(), v.end());
    for (ll i=1; i<=n; i++) A[i]=1ll*(lower_bound(v.begin(), v.end(), A[i])-v.begin()+1);
    for (ll i=1; i<=n; i++){
        update(A[i], 1, 1);
        for (ll j=2; j<=k; j++)
            update(A[i], get(A[i]-1, j-1), j);
        //ans+get(A[i]-1, k-1) khác với ans+get(A[i], k)
        //F[i][j]: số dãy tăng dần có độ dài j và kết thúc tại A[i]
        //F[i][k] = get(A[i]-1, k-1)
        //Tổng của F[m][k] = get(A[i], k) với A[m]<=A[i]
    }
    cout<< get(n, k);
    return 0;
}

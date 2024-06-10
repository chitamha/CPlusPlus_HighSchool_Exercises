#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
#define base 31
//#define MOD 1000000007
using namespace std;

ll n, ans=1, hashA[maxn], hashB[maxn], Pow[maxn];
ll MOD=1000000007;
string A, B;

ll getHash(int l, int r, long long F[]){
    ll ans=(F[r]-F[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    //ll ans=((F[r]-F[l-1]*Pow[r-l+1])%MOD+MOD)%MOD;
    return ans;
}

bool solution(int length){
    for (int i=1; i<=n-length+1; i++){
        if (getHash(i, i+length-1, hashA)==getHash(n-i-length+2, n-i+1, hashB))
            return true;
    }
    return false;
}

void cnp(int l, int r, int k){
    while (l<=r){
        ll mid=(l+r)/2;
        ll length=mid*2+k;
        if (solution(length)){
            ans=max(ans, length);
            l=mid+1;
        } else r=mid-1;
    }
}

int main(){
    cin>> n; cin.ignore();
    cin>> A;
    n=A.size(); B=A;
    reverse(B.begin(), B.end());
    A=' '+A; B=' '+B;
    //Hashing
    Pow[0]=1;
    for (int i=1; i<=n; i++) Pow[i]=(Pow[i-1]*base)%MOD;
    for (int i=1; i<=n; i++) hashA[i]=(hashA[i-1]*base+A[i]-'a'+1)%MOD;
    for (int i=1; i<=n; i++) hashB[i]=(hashB[i-1]*base+B[i]-'a'+1)%MOD;
    /*
    Tại sao lại chặt nhị phân theo length chẳn, lẻ?
    - Nếu i -> j là xâu đối xứng thì i-1 -> j-1; i -> j-1; i-1 -> j
    cũng là xâu đối xứng thì chặt nhị phân bình thường sẽ đúng
    - Nhưng mà i -> j là xâu đối xứng thì i-1 -> j-1 mới là xâu đối xứng
    nên mình phải biến đổi (xét length chẳn, lẻ)
    (VNOJ: Hàm độ dài max không đơn điệu, nên phải cnp theo các độ dài chẵn, lẻ riêng)
    */
    cnp(1, n/2+1, 0);
    cnp(1, n/2+1, 1);
    cout<< ans;
    return 0;
}

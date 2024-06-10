#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int n, k, q, maxr=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> k>> q;
    int mHieu[maxn];
    int preSmHieu[maxn];
    // preSmHieu[i]: coc thu i co bao nhieu
    // gam duong
    memset(mHieu, 0, sizeof mHieu);
    int tam=n;
    while (tam--){
        int l, r;
        cin>> l>> r;
        maxr=max(r, maxr);
        mHieu[l]+=1;
        mHieu[r+1]-=1;
    }
    preSmHieu[1]=mHieu[1];
    for (int i=2; i<=maxr; i++){
        preSmHieu[i]=preSmHieu[i-1]+mHieu[i];
    }
    // F[i]: tra loi cho cau hoi
    // "coc tai vi tri i co thoa man >=k khong?"
    // F[i] = 1 or 0
    // 1 neu (preSmHieu[i]>=k)
    // 0 neu (preSmHieu[i]<k)
    int F[maxr+5];
    memset(F, 0, sizeof F);
    for (int i=1; i<=maxr; i++){
        if (preSmHieu[i]>=k){
            F[i]=1;
        }
    }
    int preSF[maxr+5];
    // preSF[i]: mang cong don
    // tinh tong tu F[1] den F[i]
    // dung de tra loi cac truy van voi do phuc tap O(1)
    // tra loi cau hoi "trong doan tu L den R thi co bao
    // nhieu coc thoa man >=k"
    preSF[1]=F[1];
    for (int i=2; i<=maxr; i++){
        preSF[i]=preSF[i-1]+F[i];
    }
    while (q--){
        int l, r;
        cin>> l>> r;
        cout<< preSF[r]-preSF[l-1]<< endl;
    }
    return 0;
}

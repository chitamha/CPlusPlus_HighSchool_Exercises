#include <bits/stdc++.h>
using namespace std;

int n, ans=0, A[60005], Bit[60005], ma;

void update(int pos, int val){
    for (; pos<=ma; pos+=pos&(-pos))
        Bit[pos]+=val;
}

int get(int pos){
    int sum=0;
    for (; pos>=1; pos-=pos&(-pos))
        sum+=Bit[pos];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    ma=*max_element(A+1, A+n+1);
    for (int i=1; i<=n; i++){
        ans+=get(ma)-get(A[i]);
        update(A[i], 1);
    }
    cout<< ans;
    return 0;
}

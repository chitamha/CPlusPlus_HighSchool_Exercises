#include <bits/stdc++.h>
using namespace std;

int n, W, cnt=0,sum=0;
vector<int> A;

int main(){
    cin>> n>> W;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1;
    for (r; r<=n; r++){
        sum+=A[r];
        //neu sum>W => thu hep doan [l, r] = cach tang left
        while (sum>W){
            sum-=A[l];
            l++;
        }
        cnt=max(cnt, r-l+1);
    }
    cout<< cnt;
    return 0;
}

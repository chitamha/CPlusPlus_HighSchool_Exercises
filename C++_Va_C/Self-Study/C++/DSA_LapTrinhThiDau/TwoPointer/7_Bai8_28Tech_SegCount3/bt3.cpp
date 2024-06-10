#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int danhDau[100005];
set<int> chua;
int cnt=0;

int main(){
    int n, K;
    cin>> n>> K;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    int l1=n, l2=n;
    for (l1; l1>=1; l1--){
        while (chua.size()<=K && l2>=1){
            chua.insert(A[l2]);
            danhDau[A[l2]]++;
            l2--;
        }
        if (l2>=1)
            cnt+=l1-l2-1;
        else cnt+=l1;
        if (danhDau[A[l1]]!=1){
            danhDau[A[l1]]--;
        } else{
            chua.erase(A[l1]);
            danhDau[A[l1]]--;
        }
    }
    cout<< cnt;
    return 0;
}

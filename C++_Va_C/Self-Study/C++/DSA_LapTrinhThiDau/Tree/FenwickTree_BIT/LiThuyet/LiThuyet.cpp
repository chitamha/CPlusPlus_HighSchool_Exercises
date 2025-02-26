#include <bits/stdc++.h>
using namespace std;

int n, A[1000005], BIT[1000005];

void update(int pos, int val){
    for (; pos<=n; pos+=pos&(-pos)) BIT[pos]+=val;
    //pos&(-pos): vị trí số 1 cuối cùng (số 1 đầu tiên tính từ phải sang trái)
}

int get(int pos){
    int sum=0;
    for (; pos>=1; pos-=pos&(-pos)) sum+=BIT[pos];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        update(i, A[i]);
        //for (int j=i; j<=n; j+=j&(-j)) BIT[j]+=A[i];
        //cout<< i<< ": "<< BIT[i]<< endl;
    }
    cout<< get(8)-get(1);
    return 0;
}

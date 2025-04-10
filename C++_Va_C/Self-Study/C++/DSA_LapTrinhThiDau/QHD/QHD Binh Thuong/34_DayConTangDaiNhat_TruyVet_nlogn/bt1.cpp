#include <bits/stdc++.h>
using namespace std;

int n, A[1000005], before[1000005], AX[1000005];
//AX: Ánh xạ

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    A[n+1]=1e9;
    vector<int> v;
    v.push_back(A[1]);
    AX[1]=1;
    before[1]=0;
    for (int i=2; i<=n+1; i++){
        auto it=lower_bound(v.begin(), v.end(), A[i]);
        AX[it-v.begin()+1]=i;
        before[i]=AX[it-v.begin()];
        if (it==v.end()) v.push_back(A[i]);
        else *it=A[i];
    }
    cout<< v.size()-1<< endl;
    //for (int i=1; i<=v.size(); i++) cout<< AX[i]<< " "; cout<< endl;
    //for (int i=1; i<=n+1; i++) cout<< before[i]<< " "; cout<< endl;
    stack<int> st;
    for (int i=before[n+1]; i>=1; i=before[i]) st.push(i);
    while (st.size()>0){
        cout<< A[st.top()]<< " ";
        st.pop();
    }
    return 0;
}

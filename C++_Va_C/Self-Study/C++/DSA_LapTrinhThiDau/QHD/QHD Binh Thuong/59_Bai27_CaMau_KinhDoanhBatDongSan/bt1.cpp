#include <bits/stdc++.h>
using namespace std;

int n, F[60005], before[60005];

int main(){
    cin>> n;
    memset(F, 62, sizeof F);
    F[0]=0;
    for (int i=1; i<=sqrt(n); i++){
        for (int j=n; j>=i*i; j--){
            if (F[j]>F[j-i*i]+1){
                F[j]=F[j-i*i]+1;
                before[j]=i;
            }
        }
    }
    cout<< F[n]<< endl;
    int tmp=n;
    stack<int> st;
    while (tmp>0){
        st.push(before[tmp]);
        tmp-=pow(before[tmp], 2);
    }
    while (!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    return 0;
}

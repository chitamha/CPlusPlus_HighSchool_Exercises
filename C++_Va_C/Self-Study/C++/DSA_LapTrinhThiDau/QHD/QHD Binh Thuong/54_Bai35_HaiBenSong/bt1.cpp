#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, F[105], before[105];
vector<pair<int, int>> v;

int main(){
    cin>> n;
    v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i].fi>> v[i].se;
    sort(v.begin()+1, v.begin()+1+n);
    int idmax=0;
    for (int i=1; i<=n; i++){
        F[i]=1;
        for (int j=1; j<i; j++){
            if (v[i].se>v[j].se && F[i]<F[j]+1){
                F[i]=F[j]+1;
                before[i]=j;
            }
        }
        if (F[i]>F[idmax]) idmax=i;
    }
    cout<< F[n]<< endl;
    stack<int> st;
    while (idmax>0){
        st.push(idmax);
        idmax=before[idmax];
    }
    while (!st.empty()){
        cout<< v[st.top()].fi<< " "<< v[st.top()].se<< endl;
        st.pop();
    }
    return 0;
}

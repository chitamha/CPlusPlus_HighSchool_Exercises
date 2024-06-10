#include <bits/stdc++.h>
#define ll long long
#define maxn 100006
using namespace std;

int n, F[maxn], before[maxn];
struct stone{
    int d, r, c, id;
} A[maxn];

bool cmp(stone A, stone B){
    return A.d*A.r*A.c>B.d*B.r*B.c;
}

stone change(int x, int y, int z, int id){
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end(), greater<int>());
    return {v[0], v[1], v[2], id};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        int x, y, z; cin>> x>> y>> z;
        A[i]=change(x, y, z, i);
    }
    int idmax=0;
    sort(A+1, A+n+1, cmp);
    for (int i=1; i<=n; i++){
        F[i]=A[i].c;
        for (int j=0; j<i; j++){
            if (A[i].d<=A[j].d && A[i].r<=A[j].r && F[j]+A[i].c>F[i]){
                F[i]=F[j]+A[i].c;
                before[i]=j;
            }
        }
        if (F[idmax]<F[i]) idmax=i;
    }
    cout<< F[idmax]<< endl;
    int tmp=idmax;
    stack<int> st;
    while (tmp!=0){
        st.push(tmp);
        tmp=before[tmp];
    }
    cout<< st.size()<< endl;
    while (!st.empty()){
        cout<< A[st.top()].id << " "<< A[st.top()].r<< " "<< A[st.top()].d << " " << A[st.top()].c << endl;
        st.pop();
    }
    return 0;
}

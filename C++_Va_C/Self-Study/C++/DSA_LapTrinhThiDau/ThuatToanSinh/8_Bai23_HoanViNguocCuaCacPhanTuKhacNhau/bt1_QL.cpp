#include <bits/stdc++.h>
using namespace std;

int m, n=0, cnt=1;
set<int> se;
int A[1000];
bool used[1000];

void Ql(int i){
    for (int j=n; j>=1; j--){
        if (!used[j]){
            A[i]=j;
            used[j]=true;
            if (i==n){
                cout<< cnt++<< ": ";
                for (int k=1; k<=n; k++)
                    cout<< A[k]<< " ";
                cout<< endl;
            } else Ql(i+1);
            used[j]=false;
        }
    }
}

int main(){
    cin>> m;
    for (int i=1; i<=m; i++){
        int x; cin>> x;
        se.insert(x);
    }
    for (int i:se){
        n++;
        A[n]=i;
    }
    Ql(1);
    return 0;
}

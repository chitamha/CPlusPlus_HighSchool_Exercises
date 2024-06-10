#include <bits/stdc++.h>
using namespace std;

multiset<int> A;

void solution(int so, int x, multiset<int> &A){
    if (so==1){
        A.insert(x);
    } else if (so==2){
        if (A.find(x)!=A.end()){
            A.erase(A.find(x));
        }
    } else if (so==3){
        if (A.find(x)!=A.end()) cout<< "YES\n";
        else cout<< "NO\n";
    }
}

int main(){
    int n, q;
    cin>> n;
    for (int i=0; i<n; i++){
        int tam;
        cin>> tam;
        A.insert(tam);
    }
    int so, x;
    cin>> q;
    while (q--){
        cin>> so>> x;
        solution(so, x, A);
    }
    return 0;
}

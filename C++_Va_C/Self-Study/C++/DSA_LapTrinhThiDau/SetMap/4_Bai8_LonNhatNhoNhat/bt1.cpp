#include <bits/stdc++.h>
using namespace std;

multiset<int> A;

int main(){
    int n; cin>> n;
    for (int i=0; i<n; i++){
        int tam; cin>> tam;
        A.insert(tam);
    }
    int q, so, x; cin>> q;
    while (q--){
        cin>> so;
        if (so==1 || so==2){
            cin>> x;
        }
        if (so==1){
            A.insert(x);
        } else if (so==2){
            if (A.find(x)!=A.end()){
                A.erase(x);
            }
        } else if (so==3){
            cout<< *(A.begin())<< endl;
        } else if (so==4){
            cout<< *(A.rbegin())<< endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    cin>> n>> x;
    multiset<int> A;
    for (int i=0; i<n; i++){
        int tam;
        cin>> tam;
        A.insert(tam);
    }
    int dem=A.count(x);
    if (dem){
        cout<< dem<< endl;
        for (int i=0; i<dem; i++){
            cout<< x<< " ";
        }
    }
    else cout<< 0;
    return 0;
}

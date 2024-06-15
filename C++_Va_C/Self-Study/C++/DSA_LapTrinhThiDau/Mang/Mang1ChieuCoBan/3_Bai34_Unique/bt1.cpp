#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n; cin>> n;
    for (int i=0; i<n; i++){
        int tam;
        cin>> tam;
        int sz=v.size();
        if (i==0) v.push_back(tam);
        else if (tam!=v[sz-1]) v.push_back(tam);
    }
    for (int x:v) cout<< x<< " ";
    return 0;
}

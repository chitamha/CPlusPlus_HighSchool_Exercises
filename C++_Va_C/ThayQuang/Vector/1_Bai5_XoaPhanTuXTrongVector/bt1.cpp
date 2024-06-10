#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, x, check=0;
    cin>> n>> x;
    for (int i=0; i<n; i++){
        int tam; cin>> tam;
        if (tam!=x) v.push_back(tam);
        else check=1;

    }
    if (check){
        for (int i=0; i<v.size(); i++) cout<< v[i]<< " ";
    } else cout<< -1;
    return 0;
}

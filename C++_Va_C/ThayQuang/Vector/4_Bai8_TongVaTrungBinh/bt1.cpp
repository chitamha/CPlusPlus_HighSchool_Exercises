#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, tong=0; cin>> n;
    v.resize(n);
    for (int i=0; i<n; i++){
        cin>> v[i];
        tong+=v[i];
    }
    cout<< "Tong: "<< tong<< endl;
    cout<< "Trung binh: "<< fixed<< setprecision(2)<< 1.0*tong/n;
    return 0;
}

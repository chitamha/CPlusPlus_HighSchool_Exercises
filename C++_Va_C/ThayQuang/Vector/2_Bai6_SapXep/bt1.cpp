#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main(){
    cin>> n;
    v.resize(n);
    for (int &x:v) cin>> x;
    sort(v.begin(), v.end(), greater<int>());
    for (int x:v) cout<< x<< " ";
    return 0;
}

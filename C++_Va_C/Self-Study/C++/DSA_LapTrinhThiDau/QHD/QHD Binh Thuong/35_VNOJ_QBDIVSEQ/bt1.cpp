#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void solution(vector<int> ve){
    reverse(begin(ve), end(ve));
    vector<int> inc;
    for (int i=0; i<n; i++){
        auto it=lower_bound(inc.begin(), inc.end(), ve[i]);
        if (it==inc.end()) inc.push_back(ve[i]);
        else *it=ve[i];
    }
    cout<< inc.size();
}

int main(){
    cin>> n; v.resize(n);
    for (int i=0; i<n; i++) cin>> v[i];
    solution(v);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int ans=0;

int main(){
    int n, k;
    cin>> n>> k;
    v.resize(n+1);
    for (int i=1; i<=n; i++){
        cin>> v[i];
    }
    sort(v.begin(), v.end());
    for (int x:v){
        auto it=lower_bound(v.begin(), v.end(), k-x);
        if (*it==k-x){
            if (k-x!=x){
                ans=1;
                break;
            } else{
                if (*(it+1)==k-x){
                    ans=1;
                    break;
                }
            }
        }
    }
    if (ans) cout<< "YES";
    else cout<< "NO";
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m;
string s="";

int main(){
    //freopen("FIND.INP", "r", stdin);
    //freopen("FIND.OUT", "w", stdout);
    cin>> m;
    if (m<10 && m!=0) return cout<< m<< endl, 0;
    if (m==0) return cout<< 10, 0;
    while (m>=10){
        int tmp=m;
        for (ll i=9; i>=2; i--){
            if (m%i==0){
                s+=to_string(i);
                m=m/i;
                break;
            }
        }
        if (tmp==m) break;
    }
    if (s.size()!=0 && m<10){
        s+=to_string(m);
        sort(s.begin(), s.end());
        cout<< s<< endl;
    }
    //Phân tích thành 1 số nguyên tố >=10. VD: 99=9*11
    else cout<< -1<< endl;
    return 0;
}

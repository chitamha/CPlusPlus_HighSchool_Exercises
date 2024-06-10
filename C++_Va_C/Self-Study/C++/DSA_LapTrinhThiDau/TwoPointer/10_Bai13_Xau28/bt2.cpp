#include <bits/stdc++.h>
using namespace std;

string s;
int dem2, dem8, x, y, ans;

int main(){
    cin>> s;
    cin>> x>> y;
    s='@'+s;
    int l=1, r=0;
    for (l; l<=s.size()-1; l++){
        while (dem2<=x && dem8<=y && r<=s.size()-1){
            r++;
            if (s[r]=='2') dem2++;
            else dem8++;
        }
        ans=max(ans, r-l);
        if (s[l]=='2') dem2--;
        else dem8--;
    }
    cout<< ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;
int dem2, dem8, ans, x, y;

int main(){
    cin>> s;
    cin>> x>> y;
    s='a'+s;
    int l=1, r=1;
    for (r; r<=s.size()-1; r++){
        if (s[r]=='2') dem2++;
        else dem8++;
        while (dem2>x || dem8>y){
            if (s[l]=='2') dem2--;
            else dem8--;
            l++;
        }
        ans=max(ans, r-l+1);
    }
    cout<< ans;
    return 0;
}

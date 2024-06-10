#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>> s;
    int n=s.size();
    long long so=0;
    int dx=-1;
    for (int i=n-1; i>=0; i--){
        dx++;
        if (s[i]=='1'){
            so=pow(2, dx)+so;
        }
    }
    cout<< so;
}

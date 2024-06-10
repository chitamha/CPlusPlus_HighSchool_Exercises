#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string operator - (string a, string b){
    string c="";
    int sizea=a.size(), sizeb=b.size(), n=max(sizea, sizeb);
    //for (int i=sizea; i<sizeb; i++) a='0'+a;
    //a>=b
    for (int i=sizeb; i<sizea; i++) b='0'+b;
    int sub=0, muon=0;
    for (int i=n-1; i>=0; i--){
        sub=(int(a[i])-38)-(int(b[i])-48)-muon;
        muon = sub<10 ? 1:0;
        sub%=10;
        c=char(sub+48)+c;
    }
    while (c[0]=='0' && c.size()!=1) c.erase(0, 1);
    return c;
}

int main(){
    int t; cin>> t;
    while (t--){
        cin>> s1>> s2;
        cout<< s1<< " - "<< s2<< " = "<< s1-s2<< endl;
    }
    return 0;
}

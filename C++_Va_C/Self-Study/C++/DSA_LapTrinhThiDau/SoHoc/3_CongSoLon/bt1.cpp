#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string operator + (string a, string b){
    string c="";
    int sizea=a.size(), sizeb=b.size(), n=max(sizea, sizeb);
    for (int i=sizea; i<sizeb; i++) a='0'+a;
    for (int i=sizeb; i<sizea; i++) b='0'+b;
    int sum=0, nho=0;
    for (int i=n-1; i>=0; i--){
        sum=a[i]-'0'+b[i]-'0'+nho;
        nho=sum/10;
        sum%=10;
        c+=sum+'0';
    }
    if (nho!=0) c+=nho+'0';
    reverse(c.begin(), c.end());
    return c;
}

int main(){
    int t; cin>> t;
    while (t--){
        cin>> s1>> s2;
        cout<< s1<< " + "<< s2<< " = "<< s1+s2<< endl;
    }
    return 0;
}

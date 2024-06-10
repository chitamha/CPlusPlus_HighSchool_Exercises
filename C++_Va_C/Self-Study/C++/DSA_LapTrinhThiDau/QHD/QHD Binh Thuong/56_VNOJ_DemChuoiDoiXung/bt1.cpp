#include <bits/stdc++.h>
using namespace std;

string s;
string F[125][125];

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    int n=s.size(); s=' '+s;
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) F[i][j]="0";
    for (int i=0; i<=n; i++) F[i][i]="1";
    string num1="1";
    for (int i=n; i>=1; i--){
        for (int j=i+1; j<=n; j++){
            if (s[i]==s[j]) F[i][j]=F[i][j-1]+F[i+1][j]+num1;
            else F[i][j]=F[i][j-1]+F[i+1][j]-F[i+1][j-1];
        }
    }
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    cout<< F[1][n];
    return 0;
}

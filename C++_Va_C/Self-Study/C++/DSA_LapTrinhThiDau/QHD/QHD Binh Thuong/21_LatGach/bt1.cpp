#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
    string c;
    int d=abs(int(a.size())-int(b.size()));
    if (a.size()<b.size()){
        for (int i=0; i<d; i++)
            a='0'+a;
    } else{
        for (int i=0; i<d; i++)
            b='0'+b;
    }
    int right=a.size()-1;
    int r=0;
    while (right>=0){
        int tmp1=a[right]-'0';
        int tmp2=b[right]-'0';
        c+=to_string((tmp1+tmp2+r)%10);
        r=(tmp1+tmp2+r)/10;
        right--;
    }
    if (r==1) c+='1';
    reverse(c.begin(), c.end());
    return c;
}

string F[10000];

int main(){
    int t;
    cin>> t;
    while (t--){
        int n; cin>> n;
        F[1]="1";
        F[2]="2";
        for (int i=3; i<=n; i++){
            F[i]=add(F[i-1], F[i-2]);
        }
        cout<< F[n]<< endl;
    }
    return 0;
}

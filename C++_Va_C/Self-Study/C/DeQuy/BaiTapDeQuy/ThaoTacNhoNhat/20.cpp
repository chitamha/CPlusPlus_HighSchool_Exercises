#include <bits/stdc++.h>
using namespace std;
int soBuoc(int n){
    if (n==1) return 0;
    else
    {
        int res1=1e9, res2=1e9, res3=1e9;
        if (n%2==0)
            //res1=soBuoc(n/2)+1;
            return soBuoc(n/2)+1;
            //{res1=soBuoc(n/2)+1; return res1;}
        if (n%3==0)
            //res2=soBuoc(n/3)+1;
            return soBuoc(n/3)+1;
            //{res2=soBuoc(n/3)+1; return res2;}
        if (n>1)
            //res3=soBuoc(n-1)+1;
            return soBuoc(n-1)+1;
            //{res3=soBuoc(n-1)+1; return res3;}
        //return fmin(res1, fmin(res2, res3));
    }
}
int main(){
    int n;
    cin>> n;
    cout<< soBuoc(n);
    int dem=0;
    while(n!=1){
        if (n%2==0){
            dem++;
            n=n/2;
        }
        else if (n%3==0){
            dem++;
            n=n/3;
        }
        else if (n>1){
            dem++;
            n=n-1;
        }
    }
    cout<< endl<< dem;
}
